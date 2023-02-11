#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofSetColor(255);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	int radius = 230;
	int deg_span = 6;

	int mini_radius = 0;
	for (int radius = 60; radius <= 300; ) {

		ofFill();
		int mini_radius = (radius * 2 * PI) / 360 * deg_span;
		for (int deg = 0; deg < 360; deg += deg_span) {

			auto base_location = glm::vec2(cos(deg * DEG_TO_RAD) * 100, sin(deg * DEG_TO_RAD) * 100);
			auto noise_value = ofNoise(glm::vec3(base_location * 0.005, ofGetFrameNum() * 0.0075));
			auto noise_radius = ofMap(noise_value, 0, 1, radius * 0.75, radius * 1.25);

			ofDrawCircle(noise_radius * cos(deg * DEG_TO_RAD), noise_radius * sin(deg * DEG_TO_RAD), mini_radius * 0.4);
		}

		ofNoFill();
		ofBeginShape();
		for (int deg = 0; deg < 360; deg += 1) {

			auto base_location = glm::vec2(cos(deg * DEG_TO_RAD) * 100, sin(deg * DEG_TO_RAD) * 100);
			auto noise_value = ofNoise(glm::vec3(base_location * 0.005, ofGetFrameNum() * 0.0075));
			auto noise_radius = ofMap(noise_value, 0, 1, radius * 0.75, radius * 1.25);

			ofVertex(glm::vec2((noise_radius + mini_radius * 1) * cos(deg * DEG_TO_RAD), (noise_radius + mini_radius * 1) * sin(deg * DEG_TO_RAD)));
		}
		ofEndShape(true);

		ofBeginShape();
		for (int deg = 0; deg < 360; deg += 1) {

			auto base_location = glm::vec2(cos(deg * DEG_TO_RAD) * 100, sin(deg * DEG_TO_RAD) * 100);
			auto noise_value = ofNoise(glm::vec3(base_location * 0.005, ofGetFrameNum() * 0.0075));
			auto noise_radius = ofMap(noise_value, 0, 1, radius * 0.75, radius * 1.25);

			ofVertex(glm::vec2((noise_radius - mini_radius * 1) * cos(deg * DEG_TO_RAD), (noise_radius - mini_radius * 1) * sin(deg * DEG_TO_RAD)));
		}
		ofEndShape(true);

		radius += mini_radius * 2;

	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}
