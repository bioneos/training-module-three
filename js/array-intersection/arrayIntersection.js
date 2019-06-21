const fs = require('fs');
const path = require('path');

if (process.argv.length <= 2)
{
  console.error('You must enter a file name.');
  process.exit(1);
}

const arrayToString = arr => {
  let string = '';
  for (let i = 0; i < arr.length - 1; i++)
  {
    string += arr[i] + ', ';
  }
  return string + arr[arr.length - 1];
};

const filePath = path.join(__dirname, process.argv[2]);
fs.readFile(filePath, 'utf8', (err, data) => {
  if (err)
  {
    console.error(err);
    process.exit(2);
  }
  const [line1, line2] = data.split('\n');
  const list1 = line1.split(' ');
  const list2 = line2.split(' ');
  console.log(`First array: ${arrayToString(list1)}`);
  console.log(`Second array: ${arrayToString(list2)}`);
  
  const combinedList = list1.concat(list2);
  let wordInstances = {};
  combinedList.forEach(word => {
    wordInstances[word] ? wordInstances[word]++ : wordInstances[word] = 1;
  });
  let intersection = new Set();
  for (const word of Object.keys(wordInstances))
  {
    if (wordInstances[word] == 2)
    {
      intersection.add(word);
    }
  }
  const num = intersection.size;
  console.log(`There ${num === 1 ? 'is' : 'are'} ${num} word${num === 1 ? '' : 's'} in the intersection of the two arrays.`);
});
