#!/bin/sh
rm *~
git add ../program
git commit -m 'program'
rm ../include/*~
git add ../include
git commit -m 'include'
git push origin master

