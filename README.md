
MODULE
    
    - Game
        - Room
            - Instance -> Object
                       -> Audio
                       -> Sprite

Object contains a vector of Instances
a user created object is inherit to Instance
Object >> Instances
test

object ใส่ vector ของ instances

player enemy จะ ใช้ class ของ instance

เวลา สร้าง player จะถูกยัดลง object
เวลา จะเรียกฟังชั่น player.create() 
