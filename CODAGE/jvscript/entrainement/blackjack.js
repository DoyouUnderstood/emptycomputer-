let sum = 0
let hasBlackJack = false
let isAlive = false
let message = ""
let messageEl = document.getElementById("message-el")
let sumEl = document.getElementById("sum-el")
let cardsEl = document.getElementById("cards-el")
let newCard = document.getElementById("newCard-el")

function getRandomCard()
{
    let randomCard =  Math.floor(Math.random()*13) + 1;
    if(randomCard>= 11 && randomCard <= 13)
    return 10
    else if(randomCard === 1)
    return 11
    else 
    return randomCard
}
function startGame()
{
    isAlive = true
    let firstCard = getRandomCard()
    let secondCard = getRandomCard()
    cards = [firstCard, secondCard]
    sum = firstCard + secondCard
    renderGame()
}
function renderGame() {
    cardsEl.textContent = "Cards : "
    for(let i = 0; i < cards.length; i+= 1)
    {
        cardsEl.textContent += cards[i] + " "
    }
    //cardsEl.textContent = "Cards : " + cards[0] + " " + cards[1]
    sumEl.textContent = "Sum : " + sum
    if (sum <= 20) {
        message = "Do you want to draw a new card?"
    } else if (sum === 21) {
        message = "You've got Blackjack!"
        hasBlackJack = true
    } else {
        message = "You're out of the game!"
        isAlive = false
    }
    messageEl.textContent = message
}
function nwCard(){
    if(sum < 22 && isAlive == true)
    {
        let varI = getRandomCard()
        sum+=varI
        cards.push(varI)
        renderGame()
    }
}
