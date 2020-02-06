enum class TypeOfItem(val typeValue: Int) {
  Item(0),
  Coin(42),
  Artifact(43),
  Jewelry(44),
  Paper(45),
  Clothing(46),
  Weapon(47)
}

enum class RarityOfItem(val rarityValue: Byte) {
  Trash(-4),
  Joke(-3),
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

enum class AttributeCode(val code: Byte) {
  health(-126),
  stamina(-125),
  magic(-124),
  healthregen(-123),
  staminaregen(-122),
  magickaregen(-121),
  hunger(-120),
  none(0),
  strength(42),
  intelligence(43),
  willpower(44),
  agility(45),
  speed(46),
  endurance(47),
  personality(48),
  reputation(49),
  bounty(50)
}

interface Attribute {
  val attributeCode: Byte
  val value: Double
}

class NoneAttribute(): Attribute {
  override val attributeCode: Byte=AttributeCode.none.code
  override val value: Double=0.0
}

class Health(val _value: Double): Attribute {
  override val attributeCode: Byte=AttributeCode.health.code
  override val value: Double=_value
}

class Stamina(val _value: Double): Attribute {

}

class Magic(val _value: Double): Attribute {

}

class HealthRegen(val _value: Double): Attribute {

}

class StaminaRegen(val _value: Double): Attribute {

}

class MagickaRegen(val _value: Double): Attribute {

}

class Hunger(val _value: Double): Attribute {

}

class Strength(val _value: Double): Attribute {

}

class Intelligence(val _value: Double): Attribute {

}

class Willpower(val _value: Double): Attribute {

}

class Agility(val _value: Double): Attribute {

}

class Speed(val _value: Double): Attribute {

}

class Endurance(val _value: Double): Attribute {

}

class Personality(val _value: Double): Attribute {

}

class Reputation(val _value: Double): Attribute {

}

class Bounty(val _value: Double): Attribute {

}

interface Enchantment {
  val name: String
  val context: Attribute
}

fun main() {
  var test1: Attribute= Health(120.0)
  println(test1.value)
  test1= Health(126.0)
  println(test1.value)
}
