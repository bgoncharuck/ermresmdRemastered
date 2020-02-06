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

class magicEnchantment() {
  
}
