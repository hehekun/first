#!/usr/bin/python
# -*- coding:utf-8 -*-

import os
import re
import sys

regex_1 = r'(\".+(?!\\)\")'
def replaces(name):

    pattern = re.compile(regex_1,re.DOTALL)
    fo = open(name,'r')
    complete_file = []
    for line in fo:
            complete_file.append(line)
    content = ''.join(complete_file)

    fo.close()
    fo = open(name,'w')
    i = 0
    ret = content
    string=re.findall(pattern,ret)

    while(i==0):
        
        ret=re.sub(pattern,'s'+str(i),ret,1)
        i += 1

   
    fo.write(ret)
    fo.close() 
    return string
