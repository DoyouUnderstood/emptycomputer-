let countEl = document.getElementById("count-el")
let saveEL = document.getElementById("save-el")

console.log(countEl)
console.log(saveEL)
let count = 0

function increment() {
    count = count + 1
    countEl.innerText = count
}
function save()
{
    let countstr = count + "-"
    saveEL.textContent += countstr
    count = 0
    countEl.textContent = count 
}