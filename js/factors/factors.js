if (process.argv.length <= 2)
{
  console.error('You must specify a number');
  process.exit(1);
}

const dividend = parseInt(process.argv[2]);

if (dividend < 1)
{
  console.error('You must specify a positive integer ');
  process.exit(2);
}
const numbers = [ ...Array(parseInt(dividend / 2) + 1).keys() ];

let factor;
for (let idx = 0; idx < numbers.length; idx++) {
  let divisor = numbers[idx];

  if (dividend % divisor === 0) {
    factor = true;
  }

  if (factor) {
    console.log(divisor + ' is a factor of ' + dividend + '!');
  }
}
