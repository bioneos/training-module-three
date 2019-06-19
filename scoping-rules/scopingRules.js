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






























