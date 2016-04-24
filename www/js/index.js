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
var app = {

    var mediaObject = null;
    var textRecordingPath = "~/recordingToSend.mp3"

    // Application Constructor
    initialize: function() {
        this.bindEvents();

    },
    // Bind Event Listeners
    //
    // Bind any events that are required on startup. Common events are:
    // 'load', 'deviceready', 'offline', and 'online'.
    bindEvents: function() {
        document.addEventListener("deviceready", onDeviceReady, false);
        document.getElementById("speakTextButton").addEventListener('click', this.speakButton, false);
        document.getElementById("recordButton").addEventListener('click', this.startRecord, false);
        document.getElementById("playButton").addEventListener('click', this.playRecording, false);
    },

    onDeviceReady: function(textToSpeak) {
        // This is where we will initialize the Muzik Headphone server
    },

    speakText: function(textToSpeak) {
        responsiveVoice.speak(textToSpeak);
    },

    speakButton: function() {
        var textToSpeak = document.getElementById('textToSpeak').value;
        responsiveVoice.speak(textToSpeak, "US English Female", {volume: 1.5});
    },

    startRecord: function() {
        // There can only be one recording to send at a time
        if (this.mediaObject == null) {
            this.mediaObject = new Media(this.textRecordingPath, recordSuccess, recordFailure);
        }
        newRecording.startRecord();
        document.getElementById("recordButton").value = "Stop recording";
        document.getElementById("recordButton").removeEventListener('click', this.startRecord, false);
        document.getElementById("recordButton").addEventListener('click', this.stopRecord, false);
    },

    recordSuccess: function(event) {
        alert("Event successful");
    },

    recordFailure: function(event) {
        alert("Event failed:" + event);
    }

    stopRecord: function() {
        this.mediaObject.stopRecord();
        document.getElementById("recordButton").value = "Start recording";
        document.getElementById("recordButton").removeEventListener('click', this.stopRecord, false);
        document.getElementById("recordButton").addEventListener('click', this.startRecord, false);
    }

    playRecording: function() {
        if (this.mediaObject != null) {
            mediaObject.play();
        }
        else {
            alert("There is no recording to play");
        }
    }
};

app.initialize();