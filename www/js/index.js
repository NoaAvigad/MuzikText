/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

//----------------------------------//
// ------ GLOBAL VARIABLES ---------//
//----------------------------------//
// List of strings representing the pre-typed texts
// that the user can send out
var userResponses = [];

// The "current" response that will be sent/played
// if the user hits the send/play button. Is an index
// into the userReponses list.
var currentResponse = -1;

// Information about the most recent message
var mostRecentSenderName = "";
var mostRecentSenderNumber = "";
var mostRecentMessage = "No new messages";

//----------------------------------//
// -------------- APP --------------//
//----------------------------------//
var app = {

    // Application Constructor
    initialize: function() {
        this.bindEvents();
    },
    // Bind Event Listeners
    //
    // Bind any events that are required on startup. Common events are:
    // 'load', 'deviceready', 'offline', and 'online'.
    bindEvents: function() {
        document.addEventListener("deviceready", this.onDeviceReady, false);
        // document.getElementById("speakTextButton").addEventListener('click', this.speakPressed, false);
        document.getElementById("responseInputButton").addEventListener('click', this.addResponse, false);
        document.getElementById("prevButton").addEventListener('click', this.selectPrevCurrentResponse, false);
        document.getElementById("nextButton").addEventListener('click', this.selectNextCurrentResponse, false);
        document.getElementById("playButton").addEventListener('click', this.playCurrentResponse, false);
        document.getElementById("sendButton").addEventListener('click', this.sendCurrentResponse, false);
    },

    onDeviceReady: function() {
        // Starts the muzik server 
        muzik.startServer();

        // Registers all the relevant muzik gestures to functionality
        muzik.registerForGestures(app.playCurrentText, muzik.GESTURE.BUTTON_UP);
        muzik.registerForGestures(app.playCurrentResponse, muzik.GESTURE.TAP);
        muzik.registerForGestures(app.sendCurrentResponse, muzik.GESTURE_TAP_HOLD);        
        muzik.registerForGestures(app.selectNextCurrentResponse, muzik.GESTURE.SWIPE_FORWARD);
        muzik.registerForGestures(app.selectPrevCurrentResponse, muzik.GESTURE.SWIPE_BACK);

    },

    speakText: function(textToSpeak) {
        // Given a string for a text message, will "speak" the text out loud
        responsiveVoice.speak(textToSpeak, "UK English Male", {volume: 1.5});
    },

    playCurrentText: function() {
        // Plays the most recent text received and who it was from
        if (mostRecentSenderName != "") {
        app.speakText("Message from " + mostRecentSenderName + ".");
        app.speakText(mostRecentMessage);
        }
        else {
            app.speakText("No new messages.");
        }
    },

    addResponse: function() {
        // Add a user-typed response to our list of possible responses
        var responseToAdd = document.getElementById('responseInputField').value;

        if (responseToAdd.length != 0) {
            // If this is the first response to add, make it
            // the current/default response
            if (userResponses.length == 0) {
                currentResponse = 0;;
            }
            // Then add it to our list of possible responses
            userResponses.push(responseToAdd);

            // Lastly, add the response to the list displayed to the user
            var displayedResponseList = document.getElementById('userResponseList');
            var entry = document.createElement('li');
            entry.appendChild(document.createTextNode(responseToAdd));
            displayedResponseList.appendChild(entry);

            document.getElementById('responseInputField').value = "";
        }
    },

    playCurrentResponse: function() {
        // Plays the currently selected text response out loud to the user
        if (currentResponse == -1) {
            app.speakText("No responses configured.");
        }
        else {
            app.speakText(userResponses[currentResponse]);
        }
    },

    sendCurrentResponse: function() {
        // Sends the currently selected text response to the 
        // most recent sender. If we haven't received a message
        // since opening the app, we just tell the user there's no
        // one to send it to
        if (mostRecentSenderNumber == "") {
            app.speakText("There is nobody to send that to");
        }
        else {
            // TODO (Noa): SEND THE RESPONSE TEXT!
            alert("Not implemented :( ");
        }
    },

    selectNextCurrentResponse: function() {
        // Move the currently selected response text to the next one in the list

        // A currentResponse of -1 means that the current response hasn't been set yet,
        // which means that there are no responses set yet. Do nothing.
        if (currentResponse == -1) {
            return;
        }

        // If there's only one response, just stay on that one
        if (userResponses.length == 1) {
            app.speakText(userResponses[0]);
            return;
        }

        // If we're one away from the last response,
        // then we need to loop back around to the beginning of the list.
        if (currentResponse == userResponses.length -1) {
            currentResponse = 0;
            app.speakText(userResponses[currentResponse]);
        }

        // Otherwise, we move forward!
        else {
            currentResponse = currentResponse + 1;
            app.speakText(userResponses[currentResponse]);
        }
    },

    selectPrevCurrentResponse: function() {
        // Move the currently selected response text to the previous one in the list

        // A currentResponse of -1 means that the current response hasn't been set yet,
        // which means that there are no responses set yet. Do nothing.
        if (currentResponse == -1) {
            return;
        }

        // If there's only one response, just stay on that one
        if (userResponses.length == 1) {
            app.speakText(userResponses[0]);
            return;
        }

        // If we're already at the beginning of the response list,
        // then we need to loop back around to the end of the list.
        if (currentResponse == 0) {
            currentResponse = userResponses.length - 1;
            app.speakText(userResponses[currentResponse]);
        }

        // Otherwise, we move backward!
        else {
            currentResponse = currentResponse - 1;
            app.speakText(userResponses[currentResponse]);
        }
    },

    speakPressed: function() {
        // FOR TESTING
        var textToSpeak = document.getElementById('textToSpeak').value;
        app.speakText(textToSpeak);
    },   

// There are currently a quite a few problems with getting speech -> text:
//  - Recording audio with cordova is very difficult and finicky
//  - Android records audio to some weird format that most speech -> text don't take
/*
    recordStatusCallback: function (mediaStatus, error) {
      if (martinescu.Recorder.STATUS_ERROR == mediaStatus) {
        alert(error);
      }
    },

    startRecord: function() {
        alert("running start record");
        if (recorder == null) {
            alert("recorder is null, now creating a new one");
            recorder = new martinescu.Recorder(recordingPath, { sampleRate: 22050 }, app.recordStatusCallback);
            alert("recorder object created");
        }
        recorder.start();     
    },

    recordSuccess: function(event) {
        alert("Record event successful");
    },

    recordFailure: function(event) {
        alert("Record event failed");
    },

    stopRecord: function() {
        alert("Running stopRecord");
        recorder.stop();
    },

    recordPressed: function() {
        if (currentlyRecording) {
            document.getElementById('recordButton').value = "Start recording";
            app.stopRecord();
            currentlyRecording = false;
        }
        else {
            document.getElementById('recordButton').value = "Stop recording";
            app.startRecord();
            currentlyRecording = true;
        }
    },

    playFailure: function(e) {
        alert("Play failed");
    },

    playRecording: function() {
        if (recorder != null) {
            if (mediaPlayer == null) {
            mediaPlayer = new Media(recorder.location(),
                                   function() { alert("play successful"); },
                                   function() { alert("play failed"); });
            }
            player.play(recorder);
        }
        else {
            alert("There is no recording to play");
        }
    }
*/
};

app.initialize();