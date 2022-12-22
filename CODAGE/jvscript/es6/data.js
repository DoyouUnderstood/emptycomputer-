class Player{
    constructor(name,country)
    {
        this.name = name;
        this.country = country;
    }
    introduce(){
        console.log(`${this.name} was born in ${this.country}`)
    }
}
const test = new Player("messi", "argentine")
test.introduce()
class Tennisplayer extends Player
{
    constructor(name,country,age)
    {
        super(name,country);
        this.age = age;
    }
} 