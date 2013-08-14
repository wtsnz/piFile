piFile
======

As soon as I came across [philipl/pifs](https://github.com/philipl/pifs) I was mind blown by the concept. "Never worry about data again" I lol'd, yeah right.

Then I carried on reading. I didn't know what a *normal* number was, or what a *disjunctive sequence* was. I read some more, blown away at the craziest thing I have ever read **"meaning that all possible finite sequences of digits will be present somewhere in it"**, wait what?!

**ALL possible finite sequence of digits will be present somewhere in it**

Everything that *was*, everything that *is* and everything that **WILL BE**!

![alt text](http://www.reactiongifs.com/wp-content/uploads/2013/08/surprised.gif "AMAZED")


If you havent already, go check out the amazing explanation/readme at [philipl/pifs](https://github.com/philipl/pifs) then come back.


I was fascinated, and very skeptical. There is no proof that pi is this magical number that hold the answers to life the universe and everything, but if it has these magical properties, I bet somewhere it will. It contains all files on your pc right now and all files that will ever be made (even the completed project you're hating at work right now!)

The Basic Idea of piFile
===========

So pi. 3.141592654 That number you all know of, probably can remember about 5-6 digits from school? It's aparently magical. I wanted to find out.

The project that philipl release about a year ago is a filesystem for FUSE. I wanted a way to find my files in pi without all that baggage, so I made piFile, the idea being I can just play around, making things more efficient.

Eventually, the hope is that this meta data will be very small in comparison to the original file and holds the location of the file in pi. This currently will take a hell of a long time, and I'll most likely be dead waiting to 'store' all those cat gifs I have :(

Anyway, The idea is that you 'scan' pi for the files bytes and save the index of pi. This would take years on current hardware to find bug files, so we need to split the file up and search for much much smaller chunks. Simple!

How to Use piFile
==============

I'm a mac fag, and therefore use xcode to do all my c/c++/obj-c shizz, so just open it up if you've got it handy. 

I've set up a few schemes that can get you started, "File -> .PiFile" will convert the source.txt to out.pifile, therefore ".PiFile -> File" will convert that out.pifile to a file called source-from-pi-file.txt 

If you ain't on osx/xcode, just grab the source files and figure it out. I will try write instructions later, maybe.

Usage
------

To create piFile

`./pifile <sourcefile> <destinationpifile>`

To **g**enerate a normal file

`./pifile -g <sourcepifile> <destinationfile>`

dont ask me why I chose '-g' to convert a pifile to normal file, I have no idea. This will probably change in the future though.


Current Performance
========

Currently piFile just doubles the file size of the input (HA! You've read all this and now that bombshell!) so much for meta data!!!!
Yes, but this can be improved. As per the [philipl/pifs](https://github.com/philipl/pifs) this is an experimental release and is not efficient at all. 


The reason for this is that piFile currently searches pi for each and location of every byte of the source file and then saves that location, which is stored as a short (as 255 possible concurrent values reaches indexes in pi of <2000). And a short is two bytes. Things become a lot more efficient when you search for, say two bytes. I have some testing to do to make sure that all possible two byte combinations are sequential in the first < MAX_SHORT or another approach will have to be taken.


So take this as a POC for now. And we shall see what happens in the future with more computer power!


