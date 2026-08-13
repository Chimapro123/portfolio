document.querySelector(".right-text").addEventListener("mouseover", () => {
  document.querySelector("body").style.color = "rgb(236, 238, 167)";
});
document.querySelector(".dark").addEventListener("click", () => {
  document.querySelector("body").classList.toggle("dark-mode");
});

// let name = prompt("enter your name: ");
// let age = prompt("enter your age: ");

// if (name) {
//   console.log(name);
// }
// if (age < 18) {
//   console.log("user is too younge");
//   console.log = "enter your age: ";
// } else {
//   console.log("you pass");
// }
// const age = age;
// name = "name";
// console.log(`Welcome to Aptech ${name}`);

// let geolocation = window.navigator.geolocation.getCurrentPosition((p) => {
//   console.log(p.coords.latitude, p.coords.longitude, p.timestamp.toString());
// });

// console.log("hello");
