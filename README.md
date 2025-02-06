# Minitalk

**Minitalk** est un projet de communication inter-processus qui permet d'envoyer et de recevoir des messages entre un client et un serveur en utilisant les signaux UNIX. Ce projet a été conçu pour approfondir la compréhension des mécanismes de communication entre processus et de la gestion des signaux sous UNIX.

## Fonctionnalités

- **Communication par signaux UNIX :** Le client envoie des messages au serveur en utilisant des signaux.
- **Affichage en temps réel :** Le serveur affiche les messages reçus.
- **Gestion des erreurs :** Le projet inclut une gestion des erreurs pour assurer la robustesse de la communication.
- **Transmission de messages de taille variable :** Capacité à envoyer des messages de différentes longueurs.

## Prérequis

- **Système d'exploitation :** UNIX/Linux ou macOS
- **Compilateur C :** `gcc` ou `clang`
- **Outil de compilation :** `make`

## Installation

1. **Cloner le dépôt :**

   ```bash
   git clone https://github.com/Herimamy12/minitalk.git
   cd minitalk
   ```

2. **Compiler le projet :**

Le projet utilise un *Makefile* pour faciliter la compilation. Pour générer les exécutables du serveur et du client, il suffit d'exécuter la commande suivante :

    ```make
    ```

Cette commande compilera le code source et créera deux exécutables nommés *server* et *client*.

## Utilisation

1. **Lancer le serveur**

Démarrez le serveur en premier pour qu'il puisse attendre et recevoir les messages :

    ```./server
    ```

Le serveur affichera son PID (Process ID) dans le terminal, ce qui sera nécessaire pour envoyer des messages depuis le client.

2. **Envoyer un message avec le client**

Ouvrez un autre terminal et exécutez le client en fournissant le PID du serveur et le message à envoyer :

    ```./client [PID_SERVEUR] "Votre message ici"
    ```

Exemple :

    ```./client 12345 "Hello, World!"
    ```
Le serveur recevra alors le message et l'affichera dans son terminal.

## Contribution

Les contributions à ce projet sont les bienvenues ! Si vous souhaitez participer, voici les étapes à suivre :

1. Forkez ce projet.
2. Créez une branche pour chaque fonctionnalité ou correction de bug.
3. Assurez-vous que vos modifications ne cassent pas l'existant et que toutes les fonctionnalités sont correctement testées.
4. Soumettez une Pull Request pour que vos modifications puissent être examinées et fusionnées.

Nous vous encourageons également à ajouter des tests unitaires pour garantir la stabilité du projet et éviter toute régression.

#### Auteurs

- [Herimamy12](https://github.com/Herimamy12)
