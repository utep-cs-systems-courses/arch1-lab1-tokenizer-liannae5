Project 1: Tokenizer
====================
## Objective:
To create a program that can tokenize each word in a given string and keep a
history of commands used.

## Challenges:

For milestone 1, the only challenge I had at first was getting the indicator
in the UI to appear each time a new line started. I was able to fix it by
adjusting where I put he 'fputs' statement in the while loop.

I had no major challenges in milestone 2.

For milestone 3 I had trouble traversing through the entire string to tokenize
each word, because my original code would only get the first word and return
a space for the remaining slots in tokens. However I realized that if I
updated the string using word_terminator to find the end of the word before
each iteration of the for-loop, it allowed each word to be tokenized properly.

For milestone 4, I had a segmentation issue, but I realized it was because I
didn't allocate the memory for the list correctly at first and I fixed the
memory allocation line accordingly.

## Instructions:

-Use "#" followed by a string you want to tokenize

-Use "!h" to print the entire history

-Use "!" followed by the id number of history that you want to print

