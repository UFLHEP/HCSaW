#!/usr/bin/python
import sys, os, pwd, commands
import optparse, shlex, re
import math
from ROOT import *
import ROOT
from array import array


def parseOptions():

    usage = ('usage: %prog [options] datasetList\n'
             + '%prog -h for help')
    parser = optparse.OptionParser(usage)
    
    parser.add_option('-i', '--input', dest='INPUT', type='string', default='' ,help='input file name')
    parser.add_option('-o', '--output', dest='OUTPUT', type='string', default='' ,help='output file name')

    
    # store options and arguments as global variables
    global opt, args
    (opt, args) = parser.parse_args()

                        



def makeNewFile():

    global opt, args

    fo = open( opt.OUTPUT, "wb")
    
    for line in open(opt.INPUT,'r'):
        f = line.split()
        if len(f) < 1: continue
        if f[0].startswith("#"): continue

        mass = float(f[0])
        xs = float(f[1])
        scaleUp = float(f[2])
        scaleDn = float(f[3])
        pdfUp = float(f[4])
        pdfDn = float(f[5])

        totalUp = scaleUp+pdfUp
        totalDn = scaleDn+pdfDn
        
        
        fo.write("{0}  {1}  {2}  {3}  {4}  {5}  {6}  {7}\n".format(mass,xs,totalUp,totalDn,scaleUp,scaleDn,pdfUp,pdfDn))
                





if __name__ == "__main__":
    parseOptions()
    makeNewFile()

        
