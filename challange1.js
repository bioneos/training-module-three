var count = 4;

function foo() {
    var table = [count];

    /* Build the table. */
    while (count-- > 0) {
        table.push([]);
    }

    /* Fill it with numbers. */
    for (var count = 1; count < table.length; count++) {
        table[count].push(count);
    }
    return table;
}

foo(); // What does this return? And why?
//Answer here:
//https://nullprogram.com/blog/2012/11/19/ 

//There is a bug in the below code preventing the factors of 18 from being displayed accurately. Can you spot it? 
var dividend = 18;
var numbers = [2, 3, 4, 5, 6, 7, 8, 9];
var idx;

for (idx = 0; idx < numbers.length; idx++) {
  var factor;
  var divisor = numbers[idx];

  if (dividend % divisor === 0) {
    factor = true;
  }

  if (factor) {
    console.log(divisor + ' is a factor of ' + dividend + '!');
  }
}






























