const fs = require('fs');
const path = require('path');

if (process.argv.length <= 2)
{
  console.error('You must enter a file name.');
  process.exit(1);
}

const minMax = array => {
  let minimum = 0;
  let maximum = 0;
  let minimumIndex;
  let maximumIndex;
  array.forEach(numStr => {
    if (numStr < minimum)
    {
      minimum = numStr;
    }
    if (numStr > maximum)
    {
      maximum = numStr;
    }
  });
  return {
    minimum: minimum,
    maximum: maximum
  }
};

const filePath = path.join(__dirname, process.argv[2]);
fs.readFile(filePath, 'utf8', (err, data) => {
  if (err)
  {
    console.error(err);
    process.exit(2);
  }
  let numbers = data.split(' ');
  const {minimum, maximum} = minMax(numbers);
  console.log(`Minimum: ${minimum}`);
  console.log(`Maximum: ${maximum}`);
  process.exit(0);
});
