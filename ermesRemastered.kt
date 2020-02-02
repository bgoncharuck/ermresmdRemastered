enum class TypeOfItem(val typeValue: Int) {
  Coin(42),
  Artifact(43),
  Jewelry(44),
  Paper(45),
  Clothing(46),
  Weapon(47)
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

class magicEnchantment() {

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

class ancientSilverCoin(): Coin("Ancient Silver Coin", 1500, "Unknown") {

}

class ancientGoldCoin(): Coin("Anceint Gold Coin", 10000, "Unknown") {

}

open class NonEquippableArtifact(val _name: String,
  val _value: Int,
  val _rarity: Int= RarityOfItem.Enchanted.rarityValue):
  Item(TypeOfItem.Artifact.typeValue,
    _name,
    _value,
    _rarity) {

}

open class Jewelry(val _name: String,
  val _value: Int,
  val _rarity: Int= RarityOfItem.Rare.rarityValue):
  Item(TypeOfItem.Jewelry.typeValue,
    _name,
    _value,
    _rarity) {

}

open class Necklace(val _name: String,
  val _value: Int,
  val _rarity: Int= RarityOfItem.Rare.rarityValue):
  Jewelry(_name,
    _value,
    _rarity) {

}

open class Ring(val _name: String,
  val _value: Int,
  val _rarity: Int= RarityOfItem.Rare.rarityValue):
  Jewelry(_name,
    _value,
    _rarity) {

}

open class Bracelet(val _name: String,
  val _value: Int,
  val _rarity: Int= RarityOfItem.Rare.rarityValue):
  Jewelry(_name,
    _value,
    _rarity) {

}

open class Note(val _name: String,
  val _value: Int,
  val _rarity: Int= RarityOfItem.Common.rarityValue):
  Item(TypeOfItem.Paper.typeValue,
    _name,
    _value,
    _rarity) {

}

open class Book(val _name: String,
  val _value: Int,
  val _rarity: Int= RarityOfItem.MasterPiece.rarityValue):
  Note(_name,
    _value,
    _rarity) {

}

open class Clothing(val _name: String,
  val _value: Int,
  val _rarity: Int= RarityOfItem.Common.rarityValue):
  Item(TypeOfItem.Clothing.typeValue,
    _name,
    _value,
    _rarity) {

}

open class Hat(val _name: String,
  val _value: Int,
  val _rarity: Int= RarityOfItem.Common.rarityValue):
  Clothing(_name,
    _value,
    _rarity) {

}

open class Breast(val _name: String,
  val _value: Int,
  val _rarity: Int= RarityOfItem.Common.rarityValue):
  Clothing(_name,
    _value,
    _rarity) {

}

open class Gloves(val _name: String,
  val _value: Int,
  val _rarity: Int= RarityOfItem.Common.rarityValue):
  Clothing(_name,
    _value,
    _rarity) {

}

open class Shoes(val _name: String,
  val _value: Int,
  val _rarity: Int= RarityOfItem.Common.rarityValue):
  Clothing(_name,
    _value,
    _rarity) {

}

open class Armor(val _name: String,
  val _value: Int,
  val _rarity: Int= RarityOfItem.Rare.rarityValue,
  val defenceValue):
  Clothing(_name,
    _value,
    _rarity) {

}

open class Helm(val _name: String,
  val _value: Int,
  val _rarity: Int= RarityOfItem.Rare.rarityValue,
  val _defenceValue):
  Armor(_name,
    _value,
    _rarity,
    _defenceValue) {

}

open class Breastplate(val _name: String,
  val _value: Int,
  val _rarity: Int= RarityOfItem.Rare.rarityValue,
  val _defenceValue):
  Armor(_name,
    _value,
    _rarity,
    _defenceValue) {

}

open class Bracers(val _name: String,
  val _value: Int,
  val _rarity: Int= RarityOfItem.Rare.rarityValue,
  val _defenceValue):
  Armor(_name,
    _value,
    _rarity,
    _defenceValue) {

}

open class Boots(val _name: String,
  val _value: Int,
  val _rarity: Int= RarityOfItem.Rare.rarityValue,
  val _defenceValue):
  Armor(_name,
    _value,
    _rarity,
    _defenceValue) {

}

open class Weapon(val _name: String,
  val _value: Int,
  val _rarity: Int= RarityOfItem.HighQuality.rarityValue,
  val damage: Int,
  val speed: Int):
  Item(TypeOfItem.Weapon.typeValue,
    _name,
    _value,
    _rarity) {

}

open class Staff(val _name: String,
  val _value: Int,
  val _rarity: Int= RarityOfItem.HighQuality.rarityValue,
  val _damage: Int,
  val _speed: Int):
  Weapon(_name,
    _value,
    _rarity,
    _damage,
    _speed) {

}

open class MagicStaff(val _name: String,
  val _value: Int,
  val _rarity: Int= RarityOfItem.Enchanted.rarityValue,
  val _damage: Int,
  val _speed: Int,
  val magicEnchantment: magicEnchantment):
  Staff(_name,
    _value,
    _rarity,
    _damage,
    _speed) {

}

open class Mace(val _name: String,
  val _value: Int,
  val _rarity: Int= RarityOfItem.HighQuality.rarityValue,
  val _damage: Int,
  val _speed: Int):
  Weapon(_name,
    _value,
    _rarity,
    _damage,
    _speed) {

}


open class Axe(val _name: String,
  val _value: Int,
  val _rarity: Int= RarityOfItem.HighQuality.rarityValue,
  val _damage: Int,
  val _speed: Int):
  Weapon(_name,
    _value,
    _rarity,
    _damage,
    _speed) {

}


open class Spear(val _name: String,
  val _value: Int,
  val _rarity: Int= RarityOfItem.HighQuality.rarityValue,
  val _damage: Int,
  val _speed: Int):
  Weapon(_name,
    _value,
    _rarity,
    _damage,
    _speed) {

}


open class Sword(val _name: String,
  val _value: Int,
  val _rarity: Int= RarityOfItem.HighQuality.rarityValue,
  val _damage: Int,
  val _speed: Int):
  Weapon(_name,
    _value,
    _rarity,
    _damage,
    _speed) {

}


open class Bow(val _name: String,
  val _value: Int,
  val _rarity: Int= RarityOfItem.HighQuality.rarityValue,
  val _damage: Int,
  val _speed: Int):
  Weapon(_name,
    _value,
    _rarity,
    _damage,
    _speed) {

}

class EquippedItems {

}

class Inventory {

}

class Player(val _name: String) {
  val name= _name

  var currentStage= 0
  var health= 1000
  val inventory= Inventory()
}
