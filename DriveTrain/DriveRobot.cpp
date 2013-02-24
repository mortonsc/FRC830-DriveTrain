#include "WPILib.h"
#include "Gamepad.h"
#include <cmath>

class DriveRobot : public IterativeRobot {
	
	//PWM channels:
	static const int DRIVE_RIGHT = 10;
	static const int DRIVE_LEFT = 1;
	static const int LIFT_TOP = 2;
	static const int LIFT_BOTTOM = 3;
	
	static const int BUMP_UP_CHANNEL = 7;
	static const int INTAKE_CHANNEL = 9;
	
	static const int BUMP_UP_DIRECTION = 1;
	static const int INTAKE_DIRECTION = 1;
	
	static const int DRIVE_LEFT_ENCODER_A_CHANNEL = 1;
	static const int DRIVE_LEFT_ENCODER_B_CHANNEL = 2;
	static const int DRIVE_RIGHT_ENCODER_A_CHANNEL = 3;
	static const int DRIVE_RIGHT_ENCODER_B_CHANNEL = 4;
	
	static const int ELEVATOR_TOP_DIRECTION = 1;
	static const int ELEVATOR_BOTTOM_DIRECTION = 1;
	
	//These buttons control pick-up roller speed 
	static const int ROLLER_SPEED_UP = 6;
	static const int ROLLER_SPEED_DOWN = 8;

	//buttons used to shift into high and low gear
	static const int SHIFT_HIGH_BUTTON = 5;
	static const int SHIFT_LOW_BUTTON = 7;
	
	static const int GEAR_SHIFT_SOLENOID_CHANNEL = 1;
	
	static const bool HIGH_GEAR = false;
	static const bool LOW_GEAR = true;
	
	float rollerSpeed;
	float elevatorSpeed;

	Solenoid * gear_shift;
	
	Encoder * encoder1;
	Encoder * encoder2;
	
	RobotDrive * drive;
	Gamepad * gamepad;
	DriverStationLCD * lcd;
	
	Victor * left_drive;
	Victor * right_drive;
	
	Victor * bump_up;
	Victor * intake;
	
	Victor * liftTop;
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
		liftBottom = new Victor(LIFT_BOTTOM);
		
		bump_up = new Victor(BUMP_UP_CHANNEL);
		intake = new Victor(INTAKE_CHANNEL);
		
		rollerSpeed = 0.0;
		
		elevatorSpeed = 0.0;
		
		gear_shift = new Solenoid(GEAR_SHIFT_SOLENOID_CHANNEL);
		
		encoder1 = new Encoder(DRIVE_LEFT_ENCODER_A_CHANNEL, DRIVE_LEFT_ENCODER_B_CHANNEL);
		encoder2 = new Encoder(DRIVE_RIGHT_ENCODER_A_CHANNEL, DRIVE_RIGHT_ENCODER_B_CHANNEL);

		gamepad = new Gamepad(1);
		lcd = DriverStationLCD::GetInstance();
	}
	
	void DisabledInit(){
		drive->ArcadeDrive(0.0f, 0.0f);
	}
	
	void AutonInit(){
		
	}
	
	void TeleopInit(){
		encoder1->Start();
		encoder2->Start();
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
		
		//The Fancy Roller Code	
		if (rollerSpeed <= 0.99 && gamepad->GetNumberedButton(ROLLER_SPEED_UP)){
			rollerSpeed += .01;
		} else if (rollerSpeed >= .01 && gamepad->GetNumberedButton(ROLLER_SPEED_DOWN)){
			rollerSpeed -= .01;
		}
		
		bump_up->Set(rollerSpeed * BUMP_UP_DIRECTION);
		intake->Set(rollerSpeed * INTAKE_DIRECTION);
		
		Gamepad::DPadDirection dpad = gamepad->GetDPad();
		if (elevatorSpeed <= 0.99 && dpad == Gamepad::kUp)// || pressed == Gamepad::kUpLeft || pressed == Gamepad::kUpRight)
		{
			elevatorSpeed += 0.01;
		}
		if (elevatorSpeed >= 0.01 && dpad  == Gamepad::kDown)// || pressed == Gamepad::kDownLeft || pressed == Gamepad::kDownRight)
		{
			elevatorSpeed -= 0.01;
		}

		
		liftTop->Set(elevatorSpeed*ELEVATOR_TOP_DIRECTION);
		liftBottom->Set(elevatorSpeed*ELEVATOR_BOTTOM_DIRECTION);		
		
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

		int encoder_value1 = encoder1->Get();
		lcd->PrintfLine(DriverStationLCD::kUser_Line5, "encoder at %i", encoder_value1);
		
		int encoder_value2 = encoder2->Get();
		lcd->PrintfLine(DriverStationLCD::kUser_Line6, "encoder at %i", encoder_value2);
		
		lcd->UpdateLCD();		
	}
	
	float CurveAcceleration(float input) {
		//TODO: apparently we're going to do something here sometime
		return input;
	}
};

START_ROBOT_CLASS(DriveRobot)
