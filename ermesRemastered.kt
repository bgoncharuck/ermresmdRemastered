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

enum class AttributeCode(val attributeCodeValue: Byte) {
  health(-126),
  stamina(-125),
  magic(-124),
  healthregen(-123),
  staminaregen(-122),
  magickaregen(-121),
  hunger(-120),
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

interface Attribute(val _attributeCode: Byte) {
  val attributeCode: Byte= _attributeCode
  fun value()
}

class AttributeVal(val _attributeCode: Byte, val _value: Double): Attribute(_attributeCode) {
  val value: Double= _value
  override fun value() {
    return value
  }
}

class AttributeVar(val _attributeCode: Byte, val _value: Double): Attribute(_attributeCode) {
  var value: Double= _value
  override fun value() {
    return value
  }
}

class magicEnchantment(val _name: String, val _ench: Attribute) {
  val name: String= _name
  val enchantment: Attribute= _ench
}
