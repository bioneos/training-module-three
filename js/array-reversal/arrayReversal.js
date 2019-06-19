const fs = require('fs');
const path = require('path');

if (process.argv.length <= 2)
{
  console.error('You must enter a file name.');
  process.exit(1);
}

const filePath = path.join(__dirname, process.argv[2]);
fs.readFile(filePath, 'utf8', (err, data) => {
  if (err)
  {
    console.error(err);
    process.exit(2);
  }
  let words = data.split(' ');
  for (let i = 0; i < words.length; i++)
  {
    const temp = words[i];
    words[i] = words[words.length - 1 - i];
    words[words.length - 1 - i] = temp;
  }
  const output = words.join(' ');
  console.log(`Forwards: ${data}`);
  console.log(`Backwards: ${output}`);
  process.exit(0);
});
