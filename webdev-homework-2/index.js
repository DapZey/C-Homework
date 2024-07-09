const correctUsername = "admin"
const correctPassword = "123"
let personsName;
function submitButtonClicked(){
    let usernameText = document.getElementById("usernameInput")
    let passwordText = document.getElementById("password")
    document.getElementById("usernameText").style.color = "black"
    document.getElementById("passwordText").style.color = "black"
    if (usernameText.value === correctUsername && passwordText.value === correctPassword){
        personsName = window.prompt("sometext","dude");
        alert("hello, "+ personsName+"!")
        return
    }
    if (usernameText.value !== correctUsername){
        document.getElementById("usernameText").style.color = "red"
    }
    if (passwordText.value !== correctPassword){
        document.getElementById("passwordText").style.color = "red"
    }
}
