enum class TypeOfItem(val typeValue: Int) {
  Coin(42)
}

enum class RarityOfItem(val rarityValue: Byte) {
  Trash(-4),
  Joke(-3)
  Broken(-2),
  BadQuality(-1),
  Common(0),
  Modifed(1),
  HighQuality(2),
  MasterPiece(3),
  Rare(4),
  Enchanted(5),
  HighEnchanted(6),
  AncientEnchanted(7),
  Legendary(8)
}

open class Item(val _type: Int,
  val _name: String,
  val _value: Int,
  val _rarity: Byte) {

  val type= _type
  val name= _name
  val value= _value
  val rarity= _rarity
}

open class Coin(val _name: String,
  val _value: Int,
  val _coinEmbosser: String): Item(TypeOfItem.Coin.typeValue,
    _name,
    _value,
    RarityOfItem.HighQuality.rarityValue) {

  val coinEmbosser= _coinEmbosser
}

class bronzeCoin(): Coin("Bronze Coin", 50, "Mr. DuckDuck, The Bronze Lord") {

}

class silverCoin(): Coin("Silver Coin", 100, "Silver Bank of Bachin") {

}

class goldCoin(): Coin("Gold Coin", 1000, "Westburg Tallers Corp") {
  
}

class Inventory {

}

class Player(val _name: String) {
  val name= _name

  var currentStage= 0
  var health= 1000
  val inventory= Inventory()
}
