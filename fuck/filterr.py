#!/usr/bin/python
# -*- coding:utf-8 -*-

import os
import re
import sys

regex_1 = r'(//[^\n]+)|(/\*.+?\*/)'
def filterr(name):
    pattern = re.compile(regex_1,re.DOTALL);
    fo = open(name,'r')
    complete_file = []
    for line in fo:
            complete_file.append(line)
    content = ''.join(complete_file)


    ret=re.sub(pattern,'',content)

    fo.close()
    fo = open(name,'w')
    fo.write(ret)
    fo.close() 

