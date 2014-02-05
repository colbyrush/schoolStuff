#!/usr/bin/python
#
### Colby Rush, CS 210 HW#4, Python Assignment
#

from HTMLParser import HTMLParser
import sys

class MyHTMLParser(HTMLParser):
    def __init__(self):
        HTMLParser.__init__(self)
        r = open(sys.argv[1])
        self.feed(r.read())        
    def handle_starttag(self, tag, attrs):
        if tag == 'br':
            f.write('\n')
        if tag == 'p':
            f.write('\n\n')
        if tag == 'li':
            f.write('\n')
        if tag == 'tr':
            f.write('\n')
        if tag == 'h1':
            f.write('\n\n\n')
        if tag == 'h2':
            f.write('\n\n\n')
        if tag == 'h3':
            f.write('\n\n\n')
        if tag == 'h4':
            f.write('\n\n\n')
        if tag == 'h5':
            f.write('\n\n\n')
        if tag == 'h6':
            f.write('\n\n\n')
        if tag == 'a' and attrs:
            f.write('(%s)' % attrs[0][1])
        if tag == 'img' and attrs:
            f.write('(%s)' % attrs[0][1])
    def handle_endtag(self, tag):
        if tag == 'h1':
            f.write('\n\n')
        if tag == 'h2':
            f.write('\n\n')
        if tag == 'h3':
            f.write('\n\n')
        if tag == 'h4':
            f.write('\n\n')
        if tag == 'h5':
            f.write('\n\n')
        if tag == 'h6':
            f.write('\n\n')
        if tag == 'a':
            f.write('\n')
        if tag == 'img':
            f.write('\n')
    def handle_data(self, data):
        f.write(data)

f = open('HtmlTest.txt','w')
p = MyHTMLParser()
