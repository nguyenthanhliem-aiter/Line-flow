// #define sensor1 13
// #define sensor2 12 
// #define sensor3 11
// #define sensor4 10
// #define sensor5 9

// #define inA1
// #define inA2
// #define inB1
// #define inB2




// void setup() {
//   // put your setup code here, to run once:
// Serial.begin(9600); // đưa tín hiệu ra cổng giao tiếp Serial 
// pinMode(sensor1, INPUT);
// pinMode(sensor2, INPUT);
// pinMode(sensor3, INPUT);
// pinMode(sensor4, INPUT);
// pinMode(sensor5, INPUT);
// delay(1000);

// pinMode(inA1, OUTPUT);
// pinMode(inA2, OUTPUT);
// pinMode(inB1, OUTPUT);
// pinMode(inB2, OUTPUT);
// }
// void loop() {
//   // put your main code here, to run repeatedly:
//   if(digitalRead(sensor1)==0) Serial.print("Sensor1 = while ");
//   else Serial.print("Sensor1 = black");
//     if(digitalRead(sensor2)==0) Serial.print("Sensor2 = while ");
//   else Serial.print("Sensor2 = black");
//     if(digitalRead(sensor3)==0) Serial.print("Sensor3 = while ");
//   else Serial.print("Sensor3 = black");
//     if(digitalRead(sensor4)==0) Serial.print("Sensor4 = while ");
//   else Serial.print("Sensor4 = black");
//     if(digitalRead(sensor5)==0) Serial.print("Sensor5 = while ");
//   else Serial.print("Sensor5 = black");
// delay(1000);
// }

//  void dithang ()
//  {
//       digitalWrite(inA1, LOW);
//       digitalWrite(inA2,HIGH);
//       digitalWrite(inB1, LOW);
//       digitalWrite(inB2, HIGH);
// }
//   void dilui (){
//       digitalWrite(inA1, HIGH);
//       digitalWrite(inA2, LOW);
//       digitalWrite(inB1, HIGH);
//       digitalWrite(inB2, LOW);
// }
// void quaytrai(){
//    digitalWrite(inA1, HIGH);
//    digitalWrite(inA2, LOW);
//    digitalWrite(inB1,LOW);
//    digitalWrite(inB2,LOW);
//    }

//  void quayphai(){
//  digitalWrite(inA1,LOW);
//  digitalWrite(inA2,LOW);
//  digitalWrite(inB1,HIGH);
//  digitalWrite(inB2,LOW);
//  }

// Khai báo chân của module L298
const int ENA = 6;  // Enable motor A
const int IN1 = 7;  // Input 1 for motor A
const int IN2 = 8;  // Input 2 for motor A
const int ENB = 9;  // Enable motor B
const int IN3 = 10; // Input 3 for motor B
const int IN4 = 11; // Input 4 for motor B

#define sensor1 A1
#define sensor2 A2
#define sensor3 A3
#define sensor4 A4
#define sensor5 A5

void setup() {
  Serial.begin(9600);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Đặt giá trị mặc định cho chân Enable là HIGH
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
}

void loop() {
  int sens1 = digitalRead(sensor1);
  int sens2 = digitalRead(sensor2);
  int sens3 = digitalRead(sensor3);
  int sens4 = digitalRead(sensor4);
  int sens5 = digitalRead(sensor5);

  int deviation = lechvach5mat(sens1, sens2, sens3, sens4, sens5);

  switch (deviation) {
    case -3:
      // Xử lý khi lệch phải nhiều nhất
      break;

    case -2:
      // Xử lý khi lệch phải
      break;

    case -1:
      // Xử lý khi lệch phải nhẹ
      break;

    case 0:
      // Xử lý khi trên đường
      break;

    case 1:
      // Xử lý khi lệch trái nhẹ
      break;

    case 2:
      // Xử lý khi lệch trái
      break;

    case 3:
      // Xử lý khi lệch trái nhiều nhất
      break;

    default:
      // Xử lý khi không đọc được dữ liệu chính xác từ cảm biến
      break;
  }
}

int lechvach5mat(int sens1, int sens2, int sens3, int sens4, int sens5) {
  // Logic để xác định mức độ lệch dựa trên đọc từ 5 cảm biến
  int lechvach = -2 * sens1 - sens2 + sens4 + sens5;

  switch (lechvach) {
    case -3:
      return -3;
      break;

    case -2:
      return -2;
      break;

    case -1:
      return -1;
      break;

    case 0:
      return 0;
      break;

    case 1:
      return 1;
      break;

    case 2:
      return 2;
      break;

    case 3:
      return 3;
      break;

    default:
      return 0;
      break;
  }

 // Hàm điều khiển để xe chạy tiến
  moveForward();

  // Chờ 2 giây
  delay(2000);

  // Hàm điều khiển để xe chạy lùi
  moveBackward();

  // Chờ 2 giây
  delay(2000);

  // Dừng xe
  stopMotors();

  // Chờ 2 giây
  delay(2000);
}

// Hàm điều khiển để xe chạy tiến
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Hàm điều khiển để xe chạy lùi
void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// Hàm dừng xe
void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}




