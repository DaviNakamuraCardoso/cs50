import speech_recognition
import re
name  = re.compile(r'(name is | nome é)(.*)', re.IGNORECASE)
goodbye = re.compile(r'(.*)(goodbye)(.*)', re.IGNORECASE)
recognizer = speech_recognition.Recognizer()
with speech_recognition.Microphone() as source:
    print("Say something!")
    audio = recognizer.listen(source)
    print("Google Speech Recognition thinks you said:")
print(recognizer.recognize_google(audio))
words = recognizer.recognize_google(audio)
if mo := name.search(words):
    print(f"Hello, {mo.group(2)}")
elif mo := goodbye.search(words):
    print(f"{mo.group(2)} to you!")



