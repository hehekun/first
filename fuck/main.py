#!/usr/bin/python
# -*- coding:utf-8 -*-

import os
import re
import sys
import filterr
import replaces
def main(name):
    string = replaces.replaces(name)
    filterr.filterr(name)
if __name__ == '__main__':
    main('./../1.c') 
