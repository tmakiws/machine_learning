# -*- coding: utf-8 -*-
import numpy as np
from sklearn.cluster import KMeans, MeanShift
from math import sqrt, exp, log
from numpy.linalg import det, inv, norm
from scipy.stats import norm as normd
import matplotlib.pyplot as plt

PI = np.pi
N = 25 # hyperparameter : simplicity of model

def get_bic_before(cluster):
    data = np.asarray(cluster)
    num_data = len(data)
    p = data.shape[1]
    ave = np.mean(data, axis=0)
    mcov = np.cov(data.T)
    inv_mcov = inv(mcov)
    det_mcov = det(mcov)
    L = 0
    for d in data:
        f = exp(-0.5*(d-ave).dot(inv_mcov).dot((d-ave).T))/((2*PI)**(p/2)*sqrt(det_mcov))
        L += log(f)
    return -2*L  + N*2*p*log(num_data)

def get_bic_after(cluster_left, cluster_right):

    data_left, data_right = np.asarray(cluster_left), np.asarray(cluster_right)
    num_data = len(data_left) + len(data_right)
    p = data_right.shape[1]
    ave_left, ave_right = np.mean(data_left, axis=0), np.mean(data_right, axis=0)
    mcov_left, mcov_right = np.cov(data_left.T), np.cov(data_right.T)
    inv_mcov_left, inv_mcov_right = inv(mcov_left), inv(mcov_right)
    det_mcov_left, det_mcov_right = det(mcov_left), det(mcov_right)
    
    L = 0
    beta = norm(ave_left - ave_right)/sqrt((det_mcov_left + det_mcov_right))
    alpha = 0.5/normd.cdf(beta)
    
    for d in data_left:
        f = alpha*exp(-0.5*(d-ave_left).dot(inv_mcov_left).dot((d-ave_left).T))
        L += log(f)
        
    for d in data_right:
        f = alpha*exp(-0.5*(d-ave_right).dot(inv_mcov_right).dot((d-ave_right).T))
        L += log(f)

    return -2*L + N*4*p*log(num_data)
    

def xmeans(points):
    
    clusters = [points]
    km = KMeans(n_clusters=2, precompute_distances=True)
    while True:
        cur_bic = get_bic_before(clusters[0])
        updated = False
        cls_index = 0
        for i, cls in enumerate(clusters):
            km.fit(cls)
            l, r = [], []
            for j, d in enumerate(cls):
                if km.labels_[j] == 0:
                    l.append(d)
                else:
                    r.append(d)
            
            try:        
                new_bic = get_bic_after(l, r)
            except np.linalg.LinAlgError:
                continue
            print new_bic, cur_bic
            if new_bic < cur_bic:
                updated = True
                cls_index = i
                break
        if updated:
            clusters.pop(cls_index)
            clusters.extend([l, r])
            print len(clusters)
            cur_bic = new_bic
        else:
            break

    return clusters

if __name__ == '__main__':
    from sklearn.datasets.samples_generator import make_blobs
    import random

    centers = [[2, 2], [-2, -2], [2, -2], [-2, 2], [6, 6]]
    X, _ = make_blobs(n_samples=150 , centers=centers, cluster_std=0.7)
    xs = X[:,0]
    ys = X[:,1]
#    plt.show(plt.plot(xs, ys, "ro"))
    
#    print len(xmeans(X))
    clusters = xmeans(X)

    for cls in clusters:
        ncls = np.asarray(cls)
        xs = ncls[:,0]
        ys = ncls[:,1]
        col = random.randint(0, 0xffffff)
        plt.plot(xs, ys, "o", color="#%0.6x" % col)
    plt.show()
    print len(clusters)
    
    # ms = MeanShift(bin_seeding=True)
    # ms.fit(X)
    # print np.max(ms.labels_) + 1

