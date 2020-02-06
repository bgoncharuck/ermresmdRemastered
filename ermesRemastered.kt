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
  fun value(): Double
}

class AttributeConstant(val _attributeCode: Byte, val _attributeVal: Double): Attribute {
  override val attributeCode: Byte= _attributeCode
  private val _value: Double= _attributeVal
  override fun value(): Double {
    return this._value
  }
}

class AttributeChangeable(val _attributeCode: Byte, val _attributeVal: Double): Attribute {
  override val attributeCode: Byte= _attributeCode
  private var _value: Double= _attributeVal
  override fun value(): Double {
    return this._value
  }
  fun valueChange(newVal: Double) {
    this._value= newVal
  }
}

fun main() {
  val test1: AttributeChangeable= AttributeChangeable(AttributeCode.health.code, 120.0)
  println(test1.value())
  test1.valueChange(126.0)
  println(test1.value())
}
