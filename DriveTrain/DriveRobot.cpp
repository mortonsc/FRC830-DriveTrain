#include "WPILib.h"
#include "Gamepad.h"

class DriveRobot : public IterativeRobot {
	
	//PWM channels:
	static const int DRIVE_RIGHT = 1;
	static const int DRIVE_LEFT = 2;

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
		lcd->PrintfLine(DriverStationLCD::kUser_Line1,"LEFT Y %f",forwardSpeed);
		lcd->PrintfLine(DriverStationLCD::kUser_Line2,"RIGHT X %f",sideSpeed);
	
		lcd->UpdateLCD();		
	}
	
	float CurveAcceleration(float input) {
		//TODO: apparently we're going to do something here sometime
		return input;
	}
};

START_ROBOT_CLASS(DriveRobot)
