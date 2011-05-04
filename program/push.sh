#!/bin/sh
git rm *~
git add ../program
git commit -m 'program'
cd ../include/
git rm *~
git add ../include
git commit -m 'include'
git push origin master
cd ../program/

