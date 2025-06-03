<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73
<a id="readme-top"></a> -->
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
[![Contributors][contributors-shield]][contributors-url]



<!-- PROJECT LOGO -->
<br />

<h1 align="center">Pesho the Kidnapper — Summer Practice Project (10th Grade)</h1>

  <p align="center">
    🕵️ Pesho the Kidnapper Is on the Run!
    <br />
    <a href="https://github.com/MrTiNnN/Proizvodstvena-Praktika-Pesho"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/MrTiNnN/Proizvodstvena-Praktika-Pesho/issues/new?labels=bug&template=bug-report---.md">Report Bug</a>
    &middot;
    <a href="https://github.com/MrTiNnN/Proizvodstvena-Praktika-Pesho/issues/new?labels=enhancement&template=feature-request---.md">Request Feature</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Installation</a>
    </li>
    <li><a href="#usage">Usage</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

This project is a simulation where Pesho the Kidnapper tries to escape the police by jumping between platforms on a map represented as a 2D grid. The goal is to find a path for Pesho to reach a hiding spot where the police can't catch him.

<!-- <p align="right">(<a href="#readme-top">back to top</a>)</p> -->



### Built With

* [![C][C.language]][C-url]
* [![Makefile][Makefile.tool]][Makefile-url]

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->

## Installation

1. Clone the repo
   ```sh
   git clone https://github.com/MrTiNnN/Proizvodstvena-Praktika-Pesho
   ```
2. Navigate to the code directory
   ```sh
   cd pesho
   ```
3. Run your program
   ```sh
   make
   ```

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage

The program takes input from the user including:
- **Path to a file** containing the map (a grid with marked platforms)
- **Jump distance** for Pesho
- **Jump distance** for each police officer
- **Starting positions** for Pesho and the police

Each character (Pesho and the police) can only move between platforms within their jump range. Pesho starts moving before the police, giving him a chance to escape.

### 📥 Input Format

- A **text file** containing a grid-like map with platforms (example below)
- Console input:
  - Path to the map file
  - Jump range for Pesho
  - Jump range for police
  - Starting positions: row and column for each character

Example of map file:
```
                       #    

   #########     #####
    
    
         ####

      #
```

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/MrTiNnN/Proizvodstvena-Praktika-Pesho.svg?style=for-the-badge
[contributors-url]: https://github.com/MrTiNnN/Proizvodstvena-Praktika-Pesho/graphs/contributors/
[forks-shield]: https://img.shields.io/github/forks/github_username/repo_name.svg?style=for-the-badge
[forks-url]: https://github.com/github_username/repo_name/network/members
[stars-shield]: https://img.shields.io/github/stars/github_username/repo_name.svg?style=for-the-badge
[stars-url]: https://github.com/github_username/repo_name/stargazers
[issues-shield]: https://img.shields.io/github/issues/github_username/repo_name.svg?style=for-the-badge
[issues-url]: https://github.com/github_username/repo_name/issues
[license-shield]: https://img.shields.io/github/license/github_username/repo_name.svg?style=for-the-badge
[license-url]: https://github.com/github_username/repo_name/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/linkedin_username
[product-screenshot]: images/screenshot.png

[C.language]: https://img.shields.io/badge/c-0769AD?style=for-the-badge&logo=c&logoColor=white
[C-url]: https://www.w3schools.com/c/c_intro.php

[Makefile.tool]: https://img.shields.io/badge/Makefile-4A4A55?style=for-the-badge&logo=ankermake&logoColor=FF3E00
[Makefile-url]: https://makefiletutorial.com/