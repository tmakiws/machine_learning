# -*- coding: utf-8 -*-

import numpy as np
import pickle as pkl

def cross_entropy(output, teacher):
    entropy = -np.dot(np.log(output)*teacher)
    return entropy

def sigmoid(x):
    return 1. / (1+np.exp(-x))

def d_sigmoid(x):
    return sigmoid(x)*(1-sigmoid(x))

def tanh(x):
    return np.tanh(x)

def d_tanh(x):
    return 1 - tanh(x)*tanh(x)


class FullyConnectedLayer(object):
    def __init__(self, n_input, n_output, activation_function=sigmoid):
        # self.W = np.matrix(np.random.uniform(size=(n_output, n_input)))
        # self.b = np.matrix(np.random.uniform(size=(n_output)))
        # self.delta = np.matrix(np.random.uniform(size=(n_output)))
        # self.dW = np.matrix(np.random.uniform(size=(n_output, n_input)))
        self.W = np.array(np.random.uniform(size=(n_output, n_input)))
        self.b = np.array(np.random.uniform(size=(n_output)))
        self.delta = np.array(np.random.uniform(size=(n_output,1)))
        self.dW = np.array(np.random.uniform(size=(n_output, n_input)))
        self.activation_f = activation_function
        self.input = 0
        self.output = 0
        
        
    def get_output(self, x):
        #print x, type(x)
        return self.activation_f(np.dot(x, self.W.T) + self.b)

class NeuralNetwork():
    
    def __init__(self, n_input, layer_units, error_function=cross_entropy, epsilon=0.001):
        
        self._layer_units = layer_units
        self.epsilon = epsilon
        self.layers = []
        cur_input = n_input
        for cur_output in layer_units:            
            self.layers.append(FullyConnectedLayer(cur_input, cur_output))
            cur_input = cur_output

    def fprop(self, x):
        cur_output = x
        for layer in self.layers:
#            print "x:%s" % (cur_output.shape,), "W:%s" % (layer.W.T.shape,), "b:%s" % (layer.b.shape,)
            layer.input = np.dot(cur_output, layer.W.T) + layer.b
            cur_output = layer.get_output(cur_output)
            layer.output = cur_output
            #print layer.outputq
        return cur_output

    def bprop(self, teacher):
        inv_layers = self.layers[::-1]
        for i, layer in enumerate(inv_layers):
            if i == 0:
                layer.delta = layer.output - teacher
                #print layer.delta
            elif i == len(self.layers)-1:
                break
            else:
                #print "here"
                #print layer.input.shape, sum_delta.shape
#                print d_sigmoid(layer.input).shape
                if layer.activation_f == sigmoid:
                    layer.delta = d_sigmoid(layer.input)*sum_delta
                elif layer.activation_f == tanh:
                    layer.delta = d_tanh(layer.input)*sum_delta

            #layer.dW = np.dot(layer.delta.T, self.layers[i+1].output)
            #print inv_layers[i].output, inv_layers[i+1].output
#            print layer.delta.shape, inv_layers[i+1].output.shape
            layer.dW = np.dot(layer.delta.T, inv_layers[i+1].output)
            
            layer.W = layer.W - self.epsilon * layer.dW
            #print layer.W.shape, layer.delta.shape
            sum_delta = np.dot(layer.delta, layer.W)

            
    
            
if __name__ == '__main__':
    nn = NeuralNetwork(784,[1000,100,10])

    with open("mnist.pkl") as f:
        train, val, test = pkl.load(f)
        print "train:%s" % len(train[0]), "validation:%s" % len(val[0]), "test:%s" % len(test[0])
        print "\nexample of train (train[0]):\n %s" % train[0].max()

    # for row in test[0]:
    #     for i, e in enumerate(row):
    #         if i == 10:
    #             print e," ",
    #         else:
    #             break
        
    for j in xrange(1):
        train_data, train_tsig = train
        # print train_data.shape, train_tsig.shape
        
        for n, (x, t) in enumerate(zip(train_data, train_tsig)):

            if n % 1000 == 0:
                print n

            # t = [ 0 for i in xrange(t) ] + [1] + [ 0 for i in xrange(9-t)]
            # print t
            t  = [ (i==t and 1) or 0 for i in xrange(10) ]
#            print "\nnumber_of_output_units: %s" % len(t)
#            print "input:%s" % (np.array(x).shape,), "output:%s" % (np.array(t).shape,)
#            print "forward propagation"
            nn.fprop(np.array([x]))
#            print "back propagation"
            nn.bprop(np.array([t]))



    for j in xrange(1):
        test_data, test_tsig = test
        for n, (x, t) in enumerate(zip(test_data, test_tsig)):
            print t
            t = [ 0 for i in xrange(t) ] + [1] + [ 0 for i in xrange(9-t)]
            print n
            output = nn.fprop(np.array([x]))
            print output
           
               # for x in train:
    #     output = nn.fprop(np.matrix(x))
    #     print x, output
    
                 
