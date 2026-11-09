// console.log("hello world")
// name = "ikram"
//
// hi = (name) => console.log(`hello${name}`);
// hi(name)
//
  //
// greeting = "hello";
// greeting[0] = 'Y';
//
// console.log(greeting);
//
//
// Greeting = greeting.toUpperCase();
// console.log(Greeting);
//
// greeting = "a";
// console.log(greeting);

// let username;
// document.getElementById("submit").onclick = () => {
//   username = document.getElementById("mytext").value;
//   console.log(username)
//
// }

// let age;
// age = "25";
// console.log(age, typeof age);
//
// age = Number(age);
// console.log(age, typeof age);
//
// const array = [1,2,3,4,5];
// console.log(typeof array)
//
// console.log(array[0] = 67);
//
// console.log(Math.max(...array));


// let myname = "   ikramUlHaq";
// username = myname.trim().charAt(0).toUpperCase() + myname.trim().slice(1).toLowerCase();
// console.log(username)
//
//
// let age = 3
// let iam = '3'
//
// console.log(age == iam);
// console.log(age === iam);

// colors = ['yellow', 'orange', 'brown'];
// for(color of colors){
//   console.log(color)
//
// }
//
// typeofcolors = typeof colors;
// console.log(typeofcolors);

// function isValidEmail(email){
//   return email.includes("@")
// }
// console.log(isValidEmail("ikram@"))
// console.log(isValidEmail("ikram"))

// let x = 3;
//
// function test_scope(x){
//   console.log(x);
// }
// test_scope(5)
// console.log(x);

//
// sentence = "hello my name is ikram i am 20 years old";
// words = sentence.split('').reverse().join('')
// console.log(words);
//
// function reverseNumber(num){
//   reversedStr = num.toString().split('').reverse().join('')
//
//   return parseFloat(reversedStr) *  Math.sign(num)
// }
// console.log(reverseNumber(12345))

// function logallitems(...items){
//   console.log(items);
// }
//
// logallitems("hello",1,true,'hi',3.14)
//
// function trackRace(gold,silver,...rest){
//   console.log(`first${gold}, second${silver}`);
//   console.log(`rest of racers: ${rest}`);
// }
//
// trackRace('bob','alice',1,3,4,4,'ikram');
//
// let numbers = [1,2,3,4,5]
//
// numbers.forEach(square);
// numbers.forEach(display);
//
// function square(element, index, array){
//   array[index] = Math.pow(element,2)
// }
//
// function display(element){
//   console.log(element)
// }

// students = ['ikram','ans','imran']
//
// function first_char_upper(element, index, array){
//   array[index] = element.charAt(0).toUpperCase() + element.slice(1)
// }
//
// function first_char_upper_map(element){
//   return element.charAt(0).toUpperCase() + element.slice(1)
// }
// // students.forEach(first_char_upper)
// // console.log(students)
// //
// new_stds = students.map(first_char_upper_map)
// console.log(new_stds);
//
//
// const words =['Ali', 'Umar', 'Ikram', 'Ans'];
//
// function lenGreaterThan3(element){
//   return element.length > 3
// }
//
// newWords = words.filter(lenGreaterThan3)
// console.log(newWords)
//

// myfunction = (acc, val) => {
//   return acc + val;
// }
//
// myStrFunction = (acc, val) =>{
//   return acc + ' ' + val;
// } 
//
// const nums = [1,2,3,4,5,6]
// const total_sum = nums.reduce(myfunction)
// console.log(total_sum)
//
// const words = ['i', 'am', 'not', 'consistent'];
// const mySentence = words.reduce(myStrFunction);
// console.log(mySentence)


// const Person1 = {
//   firstName: 'Ikram',
//   lastName: 'haq',
//   age: 30,
//   isEmployed: true,
//   decrease_age() {this.age = this.age - 12}
// }
// Person1.lastName = 'Muhammad'
// Person1.decrease_age()
// console.log(Person1.firstName);
// console.log(Person1.lastName);
// console.log(Person1.age);
// console.log(Person1.isEmployed);


// class Product{
//   constructor(item,price){
//     this.item = item
//     this.price = price
//   }
//
//   display(){
//     console.log(this.item)
//   }
// }
//
// product1 = new Product()
// product1.display()


// class Rectangle{
//   constructor(height, width){
//     this.height = height
//     this.width = width
//   }
//   set rectangewidth(newWidth){
//     this._recwidth = newWidth
//   }
//   set rectangeheight(newheight){
//     this._height= newheight
//   }
//
//   get rectangewidth(){
//     return this._width
//   }
// }
//
// rectangle = new Rectangle(13,14)
// console.log(rectangle.width)
// console.log(rectangle.height)

// const Person= {
//   fullName: 'charles',
//   address : {
//     street: '12',
//     city: 'Monza',
//     country: 'Italy'
//   }
// }
//
// for(key,value in Person.address){
//   console.log(value);
// }


// fruits = [
//   {name:'apple', calories:45},
//   {name:'orange', calories:67},
//   {name:'banana', calories:35},
// ]
//
// console.log(fruits[0].calories)
//
// date = new Date()
// console.log(date.getFullYear())


// let x = window.prompt("enter a number")
//
// try{
//   console.log(x);
//   if(x == 0) throw new Error("cannot type 0")
// }catch(error){
//   console.error(error)
// }

let username;

document.getElementById("submit").onclick = ()=>{
  username = document.getElementById("mytext").value;
  document.getElementById("show-text").textContent= username
}



