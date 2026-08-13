// =========================
// WATER TRACKER
// =========================

let waterGlasses = 0;

const waterCount = document.getElementById("water-count");

const addWaterButton = document.getElementById("add-water");

addWaterButton.addEventListener("click", function () {
  waterGlasses++;

  waterCount.textContent = waterGlasses + " glasses today";
});

// =========================
// MOOD TRACKER
// =========================

const moodStatus = document.getElementById("mood-status");

const recordMoodButton = document.getElementById("record-mood");

recordMoodButton.addEventListener("click", function () {
  let mood = prompt("How are you feeling today?");

  if (mood !== null && mood !== "") {
    moodStatus.textContent = "Today you feel: " + mood;
  }
});

// =========================
// EXERCISE TRACKER
// =========================

const exerciseStatus = document.getElementById("exercise-status");

const addExerciseButton = document.getElementById("add-exercise");

addExerciseButton.addEventListener("click", function () {
  let exercise = prompt("How many minutes did you exercise?");

  if (exercise !== null && exercise !== "") {
    exerciseStatus.textContent = exercise + " minutes of exercise";
  }
});

// =========================
// WEIGHT TRACKER
// =========================

const weightStatus = document.getElementById("weight-status");

const addWeightButton = document.getElementById("add-weight");

addWeightButton.addEventListener("click", function () {
  let weight = prompt("Enter your weight in kilograms:");

  if (weight !== null && weight !== "") {
    weightStatus.textContent = weight + " kg";
  }
});
