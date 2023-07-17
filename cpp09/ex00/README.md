
## Summary
### Bitcoin Exchange
> The *`btc`* program is designed to process input data and perform comparisons against a supplied CSV file. This CSV file contains a comprehensive record of bitcoin values from 2009 to 2022. By utilizing this program, users can determine the worth of various quantities of bitcoin on a particular date.

<br/>

#### The program must adhere to these rules:
- program must take a file as argument.
- each line in this file must use the following format: "date | value".
- a valid date will always be in the following format: Year-Month-Day.
- a valid value must be either a float or a positive integer, between 0 and 1000


#### Sample


```
./btc ./input.txt

2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 21474

Output:

2012-01-11 => 2 = 14.2
Error! Invalid bitcoin value: -1
Error! Not valid: 2001-42-42
2012-01-11 => 1 = 7.1
Error! Invalid bitcoin value: 21474
```


