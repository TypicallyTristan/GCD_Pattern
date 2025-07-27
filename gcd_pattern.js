const readline = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

// length of the pattern arr = the number of rows in the pattern
// each row is an array of strings, where each string is a pattern of X's and O's
let examplePatternSteps = {
  // Example pattern for 5 X's and 7 O's
  step1: ["XXXXXOOOOOOO"],
  step2: ["XXXXXOO", "OOOOO"],
  step3: ["XXX", "OOO", "OO", "XX", "OO"],
  // Then concat the whole patter by getting the first index of each row
};

// Uses Euclids algorithm to find the values of each step
// a = b * q + r where a is the larger number, b is the smaller number, q is the quotient, and r is the remainder
function getGCDStep(xCount, oCount) {}

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
}

function main() {
  readline.question(
    "Enter number of X's and Y's separated by space: ",
    (input) => {
      const [xCount, oCount] = input.split(" ").map(Number);
      if (isNaN(xCount) || isNaN(oCount)) {
        console.log("Please enter valid numbers.");
      } else {
      }
      readline.close();
    }
  );
  console.log(concatenatePattern(examplePatternSteps.step3));
}

main();
