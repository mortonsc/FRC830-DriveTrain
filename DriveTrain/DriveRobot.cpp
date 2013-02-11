#include "WPILib.h"
#include "Gamepad.h"

class DriveRobot : public IterativeRobot {
	
	//PWM channels:
	static const int DRIVE_RIGHT = 1;
	static const int DRIVE_LEFT = 2;
	
	//buttons used to shift into high and low gear
	static const int SHIFT_HIGH_BUTTON = 5;
	static const int SHIFT_LOW_BUTTON = 7;
	
	static const int GEAR_SHIFT_RIGHT_CHANNEL = 1;
	static const int GEAR_SHIFT_LEFT_CHANNEL = 2;
	
	static const bool HIGH_GEAR = true;
	static const bool LOW_GEAR = false;
			
	Solenoid * right_gear_shift;
	Solenoid * left_gear_shift;
	
	RobotDrive * drive;
	Gamepad * gamepad;
	DriverStationLCD * lcd;
	
	Victor * left_drive;
	Victor * right_drive;
	
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
		
		left_gear_shift = new Solenoid(GEAR_SHIFT_LEFT_CHANNEL);
		right_gear_shift = new Solenoid(GEAR_SHIFT_RIGHT_CHANNEL);
		
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
		lcd->PrintfLine(DriverStationLCD::kUser_Line5, "Auton mode on");
		lcd->UpdateLCD();
	}
	
	void TeleopPeriodic(){
		float forwardSpeed = gamepad->GetLeftY();
		float sideSpeed = gamepad->GetRightX();
		drive->ArcadeDrive(CurveAcceleration(forwardSpeed), sideSpeed);
		
		if (gamepad->GetNumberedButton(SHIFT_LOW_BUTTON)){
			right_gear_shift->Set(LOW_GEAR);
			left_gear_shift->Set(LOW_GEAR);
		} else if (gamepad->GetNumberedButton(SHIFT_HIGH_BUTTON)){
			right_gear_shift->Set(HIGH_GEAR);
			left_gear_shift->Set(HIGH_GEAR);
		}
		
		lcd->PrintfLine(DriverStationLCD::kUser_Line1,"speed: %f",forwardSpeed);
		lcd->PrintfLine(DriverStationLCD::kUser_Line2,"rotation: %f",sideSpeed);
		
		if (right_gear_shift->Get() != left_gear_shift->Get())
			lcd->PrintfLine(DriverStationLCD::kUser_Line4, "gears mismatched");
		else if (right_gear_shift->Get() == HIGH_GEAR)
			lcd->PrintfLine(DriverStationLCD::kUser_Line4, "in high gear");
		else if (right_gear_shift->Get() == LOW_GEAR)
			lcd->PrintfLine(DriverStationLCD::kUser_Line4, "in low gear");

		
		lcd->UpdateLCD();		
	}
	
	float CurveAcceleration(float input) {
		//TODO: apparently we're going to do something here sometime
		return input;
	}
};

START_ROBOT_CLASS(DriveRobot)
