class Inventory {
  
}

class Player (val _name: String) {
  var currentStage= 0
  var health= 1000
  val name= _name
  val inventory= Inventory()
}
