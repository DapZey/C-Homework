const correctUsername = "admin"
const correctPassword = "123"
let personsName;
function submitButtonClicked(){
    let usernameText = document.getElementById("usernameInput")
    let passwordText = document.getElementById("password")
    let usernameTitle = document.getElementById("usernameText")
    let passwordTitle = document.getElementById("passwordText")
    usernameTitle.style.color = "black"
    passwordTitle.style.color = "black"
    if (usernameText.value === correctUsername && passwordText.value === correctPassword){
        personsName = window.prompt("sometext","dude");
        alert("hello, "+ personsName+"!")
        return
    }
    if (usernameText.value !== correctUsername){
        usernameTitle.style.color = "red"
    }
    if (passwordText.value !== correctPassword){
        passwordTitle.style.color = "red"
    }
}
