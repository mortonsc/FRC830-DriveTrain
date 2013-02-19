#include "WPILib.h"
#include "Gamepad.h"
#include <cmath>

class DriveRobot : public IterativeRobot {
	
	//PWM channels:
	static const int DRIVE_RIGHT = 1;
	static const int DRIVE_LEFT = 2;
	static const int LIFT_TOP = 3;
	static const int LIFT_MIDDLE = 4;
	static const int LIFT_BOTTOM = 6;
	
	static const int ENCODER_1_A_CHANNEL = 1;
	static const int ENCODER_1_B_CHANNEL = 2;
	static const int ENCODER_2_A_CHANNEL = 3;
	static const int ENCODER_2_B_CHANNEL = 4;
	
	static const int ELEVATOR_TOP_DIRECTION = 1;
	static const int ELEVATOR_MID_DIRECTION = 1;
	static const int ELEVATOR_BOT_DIRECTION = 1;
	
	//buttons used to shift into high and low gear
	static const int SHIFT_HIGH_BUTTON = 5;
	static const int SHIFT_LOW_BUTTON = 7;
	
	static const int GEAR_SHIFT_SOLENOID_CHANNEL = 1;
	
	static const bool HIGH_GEAR = false;
	static const bool LOW_GEAR = true;
	

	float elevatorSpeed;

	Solenoid * gear_shift;
	
	Encoder * encoder1;
	Encoder * encoder2;
	
	RobotDrive * drive;
	Gamepad * gamepad;
	DriverStationLCD * lcd;
	
	Victor * left_drive;
	Victor * right_drive;
	
	Victor * liftTop;
	Victor * liftMid;
	Victor * liftBottom;
	
public:
	DriveRobot() {

	}
	
	void RobotInit(){
		left_drive = new Victor(DRIVE_LEFT);
		right_drive = new Victor(DRIVE_RIGHT);
		
		drive = new RobotDrive(
				left_drive,
				right_drive
				);
		
		liftTop = new Victor(LIFT_TOP);
		liftMid = new Victor(LIFT_MIDDLE);
		liftBottom = new Victor(LIFT_BOTTOM);
		
		elevatorSpeed = 0.0;
		
		gear_shift = new Solenoid(GEAR_SHIFT_SOLENOID_CHANNEL);
		
		encoder1 = new Encoder(ENCODER_1_A_CHANNEL, ENCODER_1_B_CHANNEL);
		encoder2 = new Encoder(ENCODER_2_A_CHANNEL, ENCODER_2_B_CHANNEL);
		
		gamepad = new Gamepad(1);
		lcd = DriverStationLCD::GetInstance();
	}
	
	void DisabledInit(){
		drive->ArcadeDrive(0.0f, 0.0f);
	}
	
	void AutonInit(){
		
	}
	
	void TeleopInit(){
	}
	
	void DisabledPeriodic(){
		drive->ArcadeDrive(0.0f, 0.0f);
	}
	
	void AutonPeriodic(){
		drive->ArcadeDrive(0.5f, 0.0f);
	}
	
	void TeleopPeriodic(){
		//float forwardSpeed = gamepad->GetLeftY();
		//float sideSpeed = gamepad->GetRightX();
		//drive->ArcadeDrive(CurveAcceleration(forwardSpeed), sideSpeed);
		float leftSpeed = gamepad->GetLeftY();
		float rightSpeed = gamepad->GetRightY();
		if (leftSpeed > 1.0f)
			leftSpeed = 1.0f;
		if (leftSpeed < -1.0f)
			leftSpeed = -1.0f;
		if (rightSpeed > 1.0f)
			rightSpeed = 1.0f;
		if (rightSpeed < -1.0f)
			rightSpeed = -1.0f;
		drive->TankDrive(leftSpeed, rightSpeed);
		
		
		int pressed = 0; 
		pressed = gamepad->GetDPad();
		if (elevatorSpeed <= 0.9 && pressed == Gamepad::kUp)// || pressed == Gamepad::kUpLeft || pressed == Gamepad::kUpRight)
		{
			elevatorSpeed += 0.01;
		}
		if (elevatorSpeed >= 0.1 &&pressed  == Gamepad::kDown)// || pressed == Gamepad::kDownLeft || pressed == Gamepad::kDownRight)
		{
			elevatorSpeed -= 0.01;
		}
		
//		if (gamepad->GetDPad(LIFT_SPEED_UP)&& elevatorSpeed <= 0.9){
//			elevatorSpeed += 0.1;
//			
//		}else if (gamepad->GetDPad(LIFT_SPEED_DOWN) && elevatorSpeed >= 0.1){
//			elevatorSpeed -= 0.1;
//		}
		
		liftTop->Set(elevatorSpeed*ELEVATOR_TOP_DIRECTION);
		liftMid->Set(elevatorSpeed*ELEVATOR_MID_DIRECTION);
		liftBottom->Set(elevatorSpeed*ELEVATOR_BOT_DIRECTION);		
		
		if (gamepad->GetNumberedButton(SHIFT_LOW_BUTTON)){
			gear_shift->Set(LOW_GEAR);
		} else if (gamepad->GetNumberedButton(SHIFT_HIGH_BUTTON)){
			gear_shift->Set(HIGH_GEAR);
		}
		
		lcd->PrintfLine(DriverStationLCD::kUser_Line1,"left: %f",leftSpeed);
		lcd->PrintfLine(DriverStationLCD::kUser_Line2,"right: %f",rightSpeed);
		
		if (gear_shift->Get() == HIGH_GEAR)
			lcd->PrintfLine(DriverStationLCD::kUser_Line4, "in high gear");
		else if (gear_shift->Get() == LOW_GEAR)
			lcd->PrintfLine(DriverStationLCD::kUser_Line4, "in low gear");
		
		lcd->PrintfLine(DriverStationLCD::kUser_Line3, "elevator at %f", elevatorSpeed);

		int encoder_value1 = encoder1->GetRaw();
		lcd->PrintfLine(DriverStationLCD::kUser_Line5, "encoder at %f", encoder_value1);
		
		int encoder_value2 = encoder2->GetRaw();
		lcd->PrintfLine(DriverStationLCD::kUser_Line6, "encoder at %f", encoder_value2);
		
		lcd->UpdateLCD();		
	}
	
	float CurveAcceleration(float input) {
		//TODO: apparently we're going to do something here sometime
		return input;
	}
};

START_ROBOT_CLASS(DriveRobot)
