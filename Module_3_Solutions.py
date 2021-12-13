'''
Compilation of solutions for LBYCPA1 Module 3

big thanks sa mga chill at naka-solve ng staircase problem na nasa discord ko ngayon HAHAHAHA

Notes:
    ~ Aaralin ko lahat ng codes. Then lalagyan ko ng comments
    to help understand how the entire codeblock works.
    - sugarspicenshit
'''

# 1. Implement a Python function that accepts an positive integer and returns 
# a **list** of strings that resembles binary counting starting from zero up to 
# the input number. A non-positive input integer must return an empty list.

# References used for solution:
# Ref of bin(x)[2:] and f'{6:08b}'
# https://stackoverflow.com/questions/10411085/converting-integer-to-binary-in-python

def binaryCounter(n):
    """ Generates a list of binary counting strings up to the input number
    """
    if type(n) is not int:
        raise TypeError("Input an integer only")
        
    # YOUR CODE HERE
    elif n<0:
        return []
        
    else:
        binary_counter=[]
        for x in range(n+1):
            Counter=[bin(x)[2:]]
            binary_counter.extend(Counter)
        return binary_counter
        

# 2. A palindrome is a word, number, phrase, or other sequence of characters which 
# reads the same backward as forward such as the number 108801. Write a Python function 
# that accepts either an integer or string and returns a **tuple** consisting of two possible 
# palindromes that can be made from the input sequence.

# NOTE:
# ~ Ako gumawa neto so no need for me to change this.
# - sugarspicenshit

def toPalindrome(seq):
    """ Generates two possible palindromic sequence from the input sequence
    """
    if not (type(seq) is str or type(seq) is int):
        raise TypeError("Input a string or integer only")
        
    # YOUR CODE HERE
    
    # seq[::-1] gets the opposite sequence of a string
    # e.g. "Hello" becomes "olleH"
    # seq[::-1] only works with strings, not integers. The else condition gets the palindrome of integers.
    elif type(seq) is str:
        palindrome = (seq + seq[::-1], seq[::-1] + seq)
    
    # Gets the palindrome of integers. Consider the example seq = 123.
    #
    # 1.) Since seq[::-1] only works with strings, we have to convert seq to a string.
    # - str(seq)[::-1]
    # e.g. 123 becomes "123", then it becomes "321" because of [::-1]
    #
    # 2.) Since concatenation only works with strings, we have to convert seq to a string as well.
    # - str(seq)
    # e.g. 123 becomes "123"
    #
    # 3.) Convert them back to integers after concatenating them.
    # - int(str(seq) + str(seq)[::-1])
    # e.g. "123" + "321" become "123321", then it becomes 123321
    else:
        palindrome = (int(str(seq) + str(seq)[::-1]), int(str(seq)[::-1] + str(seq)))
        
    return palindrome
    

# 3. 3. A function is required to generate a list of pairs (x,y), each representing the 
# coordinates of the vertices of a regular convex polygon inscribed in a circle of radius r. 
# The arguments supplied to the function are the number of sides the polygon $n$ and the radius 
# of the circumscribing circle r. Implement such a function in Python, returning a list of 
# coordinates as tuples. Assume that the first vertex of the polygon must lie on the x-axis. 
# The pairs must be ordered in counterclockwise fashion. Use the `round()` function to round to 
# three decimal places only.
    
import numpy as np

def polygonVertices(n, r):
    """ Generates a list of paired tuples representing the vertices of an n-sided polygon inscribed in a circle of radius r
    """
    if not ((type(n) is int or type(n) is float) and (type(r) is int or type(r) is float)):
        raise TypeError("Input a valid number only")
    if n < 3:
        raise ValueError("Number of sides must be greater than 2")
    # YOUR CODE HERE
    else:
        polygon_vertices = []
        degrees = 360 / n
        for angles_multiply in range(n):
            angles = angles_multiply * degrees
            x_array = np.array(angles)
            multiply_x_array = r * math.cos(math.radians(x_array))
            multiply_y_array = r * math.sin(math.radians(x_array))
            xy = (round((multiply_x_array), 3), round((multiply_y_array), 3))            
            polygon_vertices.append(xy)
            
    return polygon_vertices
    

# 4. Let us extend the problem from the previous module. Given a positive n-digit number, write a Python 
# function that will return its rearranged digits such that the value of digits are in descending order 
# from left to right. For example, 87976 returns 98776 and 6740 returns 7640. Note: No import is allowed 
# for this problem.

# NOTE:
# ~ Ako gumawa neto so no need for me to change this.
# - sugarspicenshit

def numtomaxn(n):
    """This function rearranges the digits of a number to its maximum value possible
    """
    if type(n) is not int:
        raise TypeError("Input an integer only")
    # YOUR CODE HERE
    
    # Turns the number to an array of strings
    # e.g. n = 123 becomes num_list = ['1', '2', '3']
    num_list = list(str(n))
    
    # Converts all elements of num_list to integer
    # e.g. num_list = ['1', '2', '3'] becomes num_list[1, 2, 3]
    for x in range(len(num_list)):
        num_list[x] = int(num_list[x])
    
    # Sorts the list in descending order
    num_list.sort(reverse=True)
    
    # Converts back all elements of num_list to a string
    for x in range(len(num_list)):
        num_list[x] = str(num_list[x])
    
    # Concatenates all elements of num_list to a single string
    # e.g. num_list = ['1', '2', '3'] becomes result = "123"
    result = num_list[0]
    for x in range(1, len(num_list)):
        result = result + num_list[x]
    
    # Returns result as an integer    
    return int(result)
    

# 5. The bitwise logical operation NAND takes two strings and compares each character in their respective positions 
# as follows: if both of the characters is a "1", the corresponding character in the resulting string is a "0"; 
# otherwise it is a "1". Example: "10010001" NAND "10010010" becomes "01101111". Implement a Python function that 
# accepts arbitrary string length composed of "0"s and "1"s only. Both string inputs must have the same length.

# NOTE:
# ~ Ako gumawa neto so no need for me to change this.
# - sugarspicenshit

def bitwise_NAND(string1, string2):
    """This function performs the logical bitwise NAND on two n-character strings
    """
    checkInput(string1)
    checkInput(string2)
    if len(string1) != len(string2):
        raise ValueError("String inputs must have same lengths")
    # YOUR CODE HERE
    
    # Separates each character in string1 and string2 and puts them in a list.
    # e.g. string1 = "1100" and string2 = "1010" 
    # become string1_list = ['1', '1', '0', '0'] and string2_list = ['1', '0', '1', '0']
    string1_list = list(string1)
    string2_list = list(string2)
    
    # Performs "bitwise" NAND operation on each element in string1_list and string2_list.
    # NOTE: NAND simply means the negation of AND. So get the conjunction of two truth values, then negate the result.
    #
    # Each element of string1_list and string2_list will be compared with each other.
    # e.g. string1_list = ['1', '1', '0', '0'] and string2_list = ['1', '0', '1', '0']
    #                       /\                                      /\
    #                       ||                                      ||      if x = 0, DO NAND OPERATION ON THESE TWO 
    # Loop through both of these lists using a for loop from x = 0 to len(string1_list), which is 4.
    # if x = 0, do the NAND operation for 1 and 1, which is 0
    #
    # Declare a string3 variable that is empty.
    # Then just append 0 or 1 depending on the result of the NAND operation.
    #
    # e.g.
    # x = 0 -> string3 = "0"
    # x = 1 -> string3 = string3 (which is "0") + 1
    # x = 2 -> string3 = string3 (which is now "01") + 1
    # x = 3 -> string3 = string (which is now "011") + 1
    # string3 = "0111"
    string3 = ""
    for x in range(len(string1_list)):
        if string1_list[x] == "1" and string2_list[x] == "1":
            string3 = string3 + "0"
        else:
            string3 = string3 + "1"
        
    return string3

def checkInput(string):
    if type(string) is not str:
        raise TypeError("Input not a valid string")
    for char in string:
        if not (char == "0" or char == "1"):
            raise ValueError("Strings must contain a '0' or '1' characters only")


# 6. Create a Python function that returns a list of strings that resembles a pyramidal shape if printed line-by-line, 
# composed of the two characters specified by its arguments. It must accept the number of lines to generate, the 
# character to display on the left half of a single line and the character to display on the right half of the same line. 

def generate_triangle(n, left="/", right="\\"):
    """This function generates a list of strings which when printed resembles a triangle
    """
    if type(n) is not int:
        raise TypeError("Input an integer only")
    # YOUR CODE HERE
    pyramid = []
    for x in range(n + 1):
        if x > 0:
            y = n - x
            space = (" ")
            pyramid.append(space * y + left * x + right * x + space * y)
    return pyramid


# 7. A word processing system sometimes needs to shorten a word to make it fit on a line. Write a function that takes a string 
# containing a single word and decides where to hyphenate it. A hyphen can occur before the endings: "ing," "ed," "ate," "tion," 
# or "ment." It could also occur after a prefix: "pre," "post," "para," "pro," "con," or "com." Otherwise, place a hyphen somewhere 
# in the middle of the word. The function should return a tuple containing the first and second half of the word split at the hyphen.

# YEP WALA PANG SOLUTION


# 8. An message encryption method which appears similar to a Ceasar cipher substitution is to be implemented in the following way: each 
# of the characters of the alphabet is re-mapped such that the ordering of the alphabet is reversed. This means that "A" becomes a "Z", 
# "B" becomes a "Y", "W" becomes a "C" and so on. The same re-mapping is done for the numbers such that a "0" becomes a "9", an "8" becomes 
# a "2" and so on. Implement a function that take a sentence as a string and returns the encrypted message as a string.

# NOTE:
# ~ Ako gumawa neto so no need for me to change this.
# - sugarspicenshit

def encryptMessage(message):
    """ This function encrypts a message such that each character is substituted with its equivalent reversed alphabet ordering.
    """
    if type(message) is not str:
        raise TypeError("Input a string only")
    # YOUR CODE HERE
    
    # Definition time with Sugal:
    # Python Dictionary - a type of Python list that stores values, but you can customize how they can be referenced.
    #
    # e.g. 
    # car_dictionary = {
    #   "manufacturer": "Ford",
    #   "model": "Mustang",
    #   "year": "1984"
    #
    # If you want to reference "Ford", you don't type car_dictionary[0].
    #
    # Instead, you type: car_dictionary["manufacturer"].
    #
    # Dictionary to define the Caesar cipher substitution.
    # e.g. plaintext_to_caesar["a"] = "z", plaintext_to_caesar["i"] = "r"
    plaintext_to_caesar = {
        "a": "z",
        "b": "y",
        "c": "x",
        "d": "w",
        "e": "v",
        "f": "u",
        "g": "t",
        "h": "s",
        "i": "r",
        "j": "q",
        "k": "p",
        "l": "o",
        "m": "n",
        "n": "m",
        "o": "l",
        "p": "k",
        "q": "j",
        "r": "i",
        "s": "h",
        "t": "g",
        "u": "f",
        "v": "e",
        "w": "d",
        "x": "c",
        "y": "b",
        "z": "a",
        "0": "9",
        "1": "8",
        "2": "7",
        "3": "6",
        "4": "5",
        "5": "4",
        "6": "3",
        "7": "2",
        "8": "1",
        "9": "0"
    }
    
    # e.g. Encrypt "Sugal" using Caesar cipher.
    encrypted_message = ""
    
    # Loops through every character in the message input string.
    # e.g. Loops through every letter in "Sugal"
    for x in message:
        
        # Since I didn't define the Caesar substitution for capital letters,
        # x.isupper() - checks if the current letter is uppercase.
        # x.lower in plaintext_to_caesar - checks if the lowercase version of the letter is in the dictionary.\
        #
        # Both of these conditions have to be true to satisfy this condition.
        #
        # e.g. "S" in "Sugal" is a capital letter, and its lowercase version "s" is in the dictionary.
        # Therefore "S" satisfies this condition.
        if x.isupper() and x.lower() in plaintext_to_ceasar:
            # Concatenates the current encrypted_message with the Caesar cipher of the letter.
            #
            # Let's focus on "plaintext_to_caesar[x.lower()].upper()" 
            #
            # x.lower() gives the lowercase version of a string.
            # e.g. "S" in "Sugal" converted to lowercase is "s"
            # so "S".lower() = "s"
            # 
            # And that value is passed to plaintext_to_ceasar
            # "s" in the dictionary is defined as "h"
            # Hence plaintext_to_caesar[x.lower()] = "h"
            #
            # Keep in mind that we have to convert "h" to uppercase "H"
            # Hence, we use the .upper() function.
            # "h".upper() = "H"
            encrypted_message = encrypted_message + plaintext_to_ceasar[x.lower()].upper()
            
        # Checks if the (lowercase) letter is in the plaintext_to_caesar
        # 
        # e.g. "u" in "Sugal" is defined in the dictionary as "f"
        # plaintext_to_caesar["u"] = "f"
        elif x in plaintext_to_caesar:
            encrypted_message = encrypted_message + plaintext_to_caesar[x]
            
        # If the current character is not in the plaintext_to_caesar dictionary, just append it to the current encrypted_message.
        else:
            encrypted_message = encrypted_message + x
            
    return encrypted_message


# 9. Suppose we wanted to sample the sine function in regular spacing over its full period interval from  0  to  2𝜋 . Implement a 
# function that returns a list of sine values over that period and accepts a single number specifying the number of sampling points. 
# The input must be at least 2, because the bounds of the interval is included. Use the round() function to round to three decimal places only.

def sampleSine(n):
    """ This function samples the sine function by the number of points specified by its argument
    """
    if type(n) is not int:
        raise TypeError("Input an integer only")
    if n < 2:
        raise ValueError("Input sample must be at least 2 points")
    # YOUR CODE HERE
    else:
        sine_values = []
        #I got the degrees via https://digitalcommons.unl.edu/cgi/viewcontent.cgi?article=1011&context=mathclass
        degrees = 360 / (n-1)
        for angles_multiply in range(n):
            angles = [angles_multiply * (degrees)]
            y_array = np.array(angles)
            multiply_y_array = math.sin(math.radians(y_array)) 
            y = round(multiply_y_array, 3)
            sine_values.append(y)
            
        return sine_values


# 10. Given the list of student ID numbers and their section, implement a function that rearranges the list with each entry a tuple of the form 
# (ID, Section) and then removes any duplicate entries. A tuple entry is a duplicate of another if both the ID and Section is the same for both tuples.

def reorganize(n):
    """ This function samples the sine function by the number of points specified by its argument
    """
    if type(n) is not list:
        raise TypeError("Input must be a list")
    # YOUR CODE HERE
    else:
        # Make each pair a tuple
        ntuple=[]
        for x in range(0,len(n),2):
            x=0
            a=n.pop(x)
            b=n.pop(x)
            c=[]
            c.append(a)
            c.append(b)
            d = tuple(c)
            ntuple.append(d)
        temp=ntuple
        dupes=[] #arranges all the dupes together
        for x in range(0,len(ntuple)):
            for y in range(0,len(ntuple)):
                if ntuple[x] == ntuple[y]:
                    dupes.append(ntuple[x])
        DUPE=list(dupes)
    DUPE = list(dict.fromkeys(DUPE))
    #https://www.w3schools.com/python/python_howto_remove_duplicates.asp
    return DUPE


studentList = [
    11910739,"EEQ1",
    11914785,"EEQ1",
    11946520,"EEQ1",
    11922443,"EEQ1",
    11915080,"EEQ1",
    11942878,"EEQ1",
    11914211,"EEQ1",
    11937920,"EQ3",
    11948884,"EQ3",
    11906235,"EQ3",
    11915307,"EQ3",
    11933003,"EEQ1",
    11946520,"EEQ1",
    11946520,"EEQ1",
    11944021,"EEQ1",
    11942878,"EEQ1",
    11913231,"EQ3",
    11828676,"EEQ1",
    11930888,"EQ3",
    11916036,"EQ3",
    11914785,"EEQ1",
    11914777,"EQ3",
    11918403,"EEQ1",
    11910739,"EEQ1",
    11916273,"EQ3",
    11945222,"EQ3",
    11917199,"EEQ1",
    11800968,"EEQ1",
    11939036,"EEQ1",
    11917121,"EQ3",
    11939036,"EEQ1",
    11946768,"EQ3",
    11915404,"EQ3",
    11937920,"EQ3",
    11906235,"EQ3",
    11914130,"EQ3",
    11927879,"EQ3",
    11917326,"EQ3",
    11914785,"EEQ1",
    11916966,"EEQ1",
    11922443,"EEQ1"]        