#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
    string title;
    int duration;

public:
    Media(string t, int d) {
        title = t;
        duration = d;
    }

    virtual void play() {
        cout << "Playing Media: " << title << endl;
    }

    string getTitle() {
        return title;
    }

    int getDuration() {
        return duration;
    }

    bool operator>(Media& other) {
        return duration > other.duration;
    }

    bool operator<(Media& other) {
        return duration < other.duration;
    }
};

class Video : public Media {
public:
    Video(string t, int d) : Media(t, d) {}

    void play() {
        cout << "Playing Video: " << title << endl;
    }
};

class Audio : public Media {
public:
    Audio(string t, int d) : Media(t, d) {}

    void play() {
        cout << "Playing Audio: " << title << endl;
    }
};

class Podcast : public Media {
public:
    Podcast(string t, int d) : Media(t, d) {}

    void play() {
        cout << "Playing Podcast: " << title << endl;
    }
};

class MediaPlayer {
public:
    void playMedia(Media* m) {
        m->play();
    }

    void playMedia(string t, double speed) {
        cout << t << " at " << speed << "x speed" << endl;
    }

    void playMedia(string t, int mins) {
        cout << t << " for " << mins << " mins" << endl;
    }

    void playMedia(string t) {
        cout << t << " with custom settings" << endl;
    }
};

int main() {
    Video v("Travel Vlog", 15);
    Audio a("Relaxing Music", 5);
    Podcast p("Tech Talk", 30);

    Media* items[3];
    items[0] = &v;
    items[1] = &a;
    items[2] = &p;

    cout << "Media Items:" << endl;
    cout << endl;
    cout << "Video: " << v.getTitle() << ", Duration: " << v.getDuration() << " mins" << endl;
    cout << "Audio: " << a.getTitle() << ", Duration: " << a.getDuration() << " mins" << endl;
    cout << "Podcast: " << p.getTitle() << ", Duration: " << p.getDuration() << " mins" << endl;

    MediaPlayer mp;

    cout << endl;
    cout << "Playing Media:" << endl;
    for (int i = 0; i < 3; i++) {
        mp.playMedia(items[i]);
    }

    cout << endl;
    cout << "Playing with Overloaded Functions:" << endl;
    mp.playMedia("Travel Vlog", 1.5);
    mp.playMedia("Relaxing Music", 3);
    mp.playMedia("Tech Talk");

    cout << endl;
    cout << "Comparisons:" << endl;
    if (p > v)
        cout << "Tech Talk > Travel Vlog" << endl;
    if (a < v)
        cout << "Relaxing Music < Travel Vlog" << endl;

    cout << endl;
    cout << "Total Media Items: 3" << endl;

    return 0;
}
