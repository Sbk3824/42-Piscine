### Test Cases:

3 - 2 <br>
1 + 2 * 4 % 2<br>
3 + 42 * (1 - 2 / (3 + 4) - 1 % 21) + 2 <br>
42 <br>
-42 <br> 
1+12 <br>
3+42*(1-2/(3+4)-1%21)+1 <br>
((((((((0))))))))

### Results

MOULINETTE 45 % [ex00: Segmentation fault in test case -42]
Overall 60 %

### Failed Test Cases 

-42 <br> 
3+42*(1-2/(3+4)-1%21)+1 <br>

Need to handle unary operatory, -42, 2+(-2) etc
