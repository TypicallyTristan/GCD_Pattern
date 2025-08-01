const readline = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

// Uses Euclids algorithm to find the values of each step
// a = b * q + r where a is the larger number, b is the smaller number, q is the quotient, and r is the remainder
function getGCDStep(xCount, oCount) {
  let a = Math.max(xCount, oCount);
  let b = Math.min(xCount, oCount);
  let r = a % b;
  let q = (a - r) / b;

  return { a, b, q, r };
}

// Given an array of strings, concatenate through the index 0 to length of the array of the strings
// ex: ["XX", "OO"] will concatenate to ["XOXO"]
function concatenatePattern(patternStep) {
  const maxColLength = Math.max(...patternStep.map((row) => row.length));
  let result = "";

  for (let col = 0; col < maxColLength; col++) {
    for (let row = 0; row < patternStep.length; row++) {
      if (patternStep[row][col] !== undefined) {
        result += patternStep[row][col];
      }
    }
  }

  return result;
}

function printStep(step) {
  for (let row of step) {
    console.log(row);
  }
  console.log("-----");
}

function moveColumns(patternStep) {
  // When there is only one row split the row into two parts
  if (patternStep.length <= 1) {
    const xCount = patternStep[0].match(/X/g)?.length || 0;
    const oCount = patternStep[0].match(/O/g)?.length || 0;
    patternStep = [
      patternStep[0].slice(0, Math.max(xCount, oCount)),
      patternStep[0].slice(-Math.min(xCount, oCount)),
    ];
    moveColumns(patternStep);
  }

  const difference = getRowLengthDifference(patternStep);
  const shortestRowLength = patternStep.reduce(
    (min, row) => Math.min(min, row.length),
    Infinity
  );

  if (difference <= 1) {
    return patternStep;
  } else {
    patternStep.forEach((row, index) => {
      if (row.length > shortestRowLength) {
        const trimmedRow = patternStep[index].substring(
          0,
          Math.max(shortestRowLength, difference)
        );
        const cutOffCharacters = patternStep[index].substring(
          Math.max(shortestRowLength, difference)
        );

        patternStep[index] = trimmedRow;
        patternStep.push(cutOffCharacters);
      }
    });

    moveColumns(patternStep);
  }
  return patternStep;
}

function getRowLengthDifference(patternStep) {
  const longestRow = patternStep.reduce(
    (max, row) => Math.max(max, row.length),
    0
  );
  const shortestRow = patternStep.reduce(
    (min, row) => Math.min(min, row.length),
    Infinity
  );
  return longestRow - shortestRow;
}

function main() {
  readline.question(
    "Enter number of X's and O's separated by space: ",
    (input) => {
      const [xCount, oCount] = input.split(" ").map(Number);
      if (isNaN(xCount) || isNaN(oCount)) {
        console.log("Please enter valid numbers.");
      } else {
        // Process the input here
        console.log(`Processing ${xCount} X's and ${oCount} O's`);
        let initialRow = "";
        for (i = 0; i < xCount; i++) {
          initialRow += "X";
        }
        for (i = 0; i < oCount; i++) {
          initialRow += "O";
        }

        const finalPattern = moveColumns([initialRow]);
        printStep(finalPattern);
        console.log(concatenatePattern(finalPattern));
      }
      readline.close();
    }
  );
}

main();
