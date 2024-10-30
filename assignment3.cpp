/*Assignment No.3

Name-Snehal Uday Shinde
PRN-123B1B264
Assignment Title: Consider the playlist in a music player. Implement a playlist feature in music player application using singly linked list. Each song in the playlist is represented as a node in the linked list. Each node contains information about the song (such as title or artist or duration, etc.). The playlist should allow users to: a. Add songs b. Remove songs c. Display the entire playlist d. Play specific songs.*/


#include <iostream>
using namespace std;

class Node {
public:
    string title;
    string artist;
    double duration;  // Duration of the song
    Node* next;

    // Constructor for creating a new song node
    Node(string t, string a, double d) {
        title = t;
        artist = a;
        duration = d;
        next = nullptr;
    }
};

class Playlist {
private:
    Node* head;  // Head of the linked list

public:
    // Constructor for initializing the playlist
    Playlist() {
        head = nullptr;
    }

    // Function to add a new song to the playlist
    void addSong(string title, string artist, double duration) {
        Node* newSong = new Node(title, artist, duration);

        if (!head) {
            head = newSong;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newSong;
        }
        cout << "Song added: " << title << endl;
    }

    // Function to remove a song from the playlist
    void removeSong(string title) {
        if (!head) {
            cout << "Playlist is empty, cannot remove song.\n";
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        // If the song to be removed is the head
        if (temp != nullptr && temp->title == title) {
            head = temp->next;
            delete temp;
            cout << "Song removed: " << title << endl;
            return;
        }

        // Search for the song to be removed
        while (temp != nullptr && temp->title != title) {
            prev = temp;
            temp = temp->next;
        }

        // If the song was not found
        if (temp == nullptr) {
            cout << "Song not found: " << title << endl;
            return;
        }

        // Unlink the node from the linked list
        prev->next = temp->next;
        delete temp;
        cout << "Song removed: " << title << endl;
    }

    // Function to display the entire playlist
    void displayPlaylist() {
        if (!head) {
            cout << "Playlist is empty.\n";
            return;
        }

        Node* temp = head;
        int count = 1;
        cout << "Playlist:\n";
        while (temp) {
            cout << count++ << ". " << temp->title << " by " << temp->artist << " (" << temp->duration << " mins)\n";
            temp = temp->next;
        }
    }

    // Function to play a specific song
    void playSong(string title) {
        if (!head) {
            cout << "Playlist is empty, cannot play song.\n";
            return;
        }

        Node* temp = head;
        while (temp) {
            if (temp->title == title) {
                cout << "Now playing: " << temp->title << " by " << temp->artist << " (" << temp->duration << " mins)\n";
                return;
            }
            temp = temp->next;
        }

        cout << "Song not found: " << title << endl;
    }
};

int main() {
    Playlist myPlaylist;

    myPlaylist.addSong("Shape of You", "Ed Sheeran", 4.24);
    myPlaylist.addSong("Blinding Lights", "The Weeknd", 3.22);
    myPlaylist.addSong("Levitating", "Dua Lipa", 3.40);

    cout << endl;
    myPlaylist.displayPlaylist();

    cout << endl;
    myPlaylist.playSong("Blinding Lights");

    cout << endl;
    myPlaylist.removeSong("Levitating");

    cout << endl;
    myPlaylist.displayPlaylist();

    return 0;
}
