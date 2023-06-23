# CS-300-T5501-DSA-Analysis-and-Design

This course had two projects that were related to each other. The first was to design a program that would take a text file and store the information in memory. The text file contained a University class number, a description and any requirements the class need. It also wanted to manipulate the data such as in some sort of order and search for specific class. This was coupled with a report on the your reasoning why you used the features you did. The second project was to implement this in C++.

As someone who works with spreadsheet and data for a living currently, I designed things in a very logic way. For instance, I found the easiest way to organize the data was to convert all the class codes to a numerical value and adding it together, with the alphabet being weighted more than the numbers. This provided a quick sort option since these were now numbers. It also made the searching better since you could search larger lists by doing binary tree search if needed.

My initial plan was to use a linked list for storing the data, however that did not work. I tried for several days to get it to work but it just never did. In the end I fell back on vectors to store the data. I created multiple vectors. This worked well with the push back feature. The sort was performed on the numerical number and then applied to all vectors. This made sure the data followed each ones spot in the individual vectors.

Even though the linked list didn't work I still like them. I will attempt to use them again. Also the sorting methods are fascinating, the binary sort being my favorite. I like you cut out half the list with the first check. 

I placed a lot of different features in there own function. I was going to use classes when the linked list was the idea but when switching to a vector that was no longer needed. Every function I made has an explanation before it what it does with explanation on the lines what it does in the function.
