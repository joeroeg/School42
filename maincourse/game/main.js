import { initMaterials } from './materials.js';
import { initGeometry } from './geometry.js';
import { initRenderer } from './renderer.js';
import { initGUI, loadSavedParameters} from './gui.js';
import { initScene, initCamera, initLights, initStats, onWindowResize } from './initialize.js';
import { initControls } from './events.js';
import { initStarField, updateStars } from './objects.js';
import { initEffectComposer } from './composer.js';
import { g } from './globals.js';
const savedLang = localStorage.getItem('lang') || 'en';
import * as THREE from 'three';
import { FontLoader } from 'three/addons/loaders/FontLoader.js';
import { TextGeometry } from 'three/addons/geometries/TextGeometry.js';
import {
    updateLighting,
    movePlayerPaddle,
    movePlayer2Paddle,
    movePlayer3Paddle,
    movePlayer4Paddle,
    moveAIPaddle,
    moveBall,
    handleCollisions,
    checkMissedBall,
    checkBounds,
    initScoreDisplay,
    orbitalRotation,
} from './animation.js';


init();
animate();

function init() {
    g.container = document.getElementById('container');    // Get the container element from the HTML document
    loadSavedParameters();
    initScene();                                           // Initialize the scene
    initCamera();                                          // Initialize the camera
    initLights();                                          // Initialize the lights
    initMaterials();                                       // Initialize the materials
    initGeometry();                                        // Initialize the geometry
    initStarField();                                       // Initialize the star field
    initRenderer(animate);                                 // Initialize the renderer
    initGUI(savedLang);                                             // Initialize the GUI
    initControls();                                        // Setup the controls for the player paddle
    initScoreDisplay();                                    // Initialize the score display
    // initStats();                                           // Initialize the stats
    // initEffectComposer();                                  // Initialize the effect composer
}

function animate() {
    onWindowResize();
    updateLighting();
    movePlayerPaddle();
    if (!g.isSinglePlayer) {
        movePlayer2Paddle();
        movePlayer3Paddle();
        movePlayer4Paddle();
    } else {
        movePlayer2Paddle();
        // moveAIPaddle();
    }
    moveBall();
    handleCollisions();
    checkMissedBall();
    checkBounds();
    orbitalRotation();
    g.renderer.render(g.scene, g.camera);
    updateStars();
    // g.stats.update();
    // g.composer.render(); // Uncomment this line to enable post-processing effects
}

g.container = document.getElementById('container');
g.container.appendChild(g.renderer.domElement);

function onMouseMove(event) {
    // Calculate mouse position in normalized device coordinates (-1 to +1) for both components
    mouse.x = (event.clientX / window.innerWidth) * 2 - 1;
    mouse.y = -(event.clientY / window.innerHeight) * 2 + 1;
}

// Add event listener for mouse movements
window.addEventListener('mousemove', onMouseMove, false);

function createTextMesh(text, position) {
    const loader = new FontLoader();
    loader.load('https://threejs.org/examples/fonts/helvetiker_regular.typeface.json', (font) => {
        const geometry = new TextGeometry(text, {
            font: font,
            size: 0.5,
            depth: 0.05,
        });

        const material = new THREE.MeshBasicMaterial({ color: 0xff });
        const textMesh = new THREE.Mesh(geometry, material);
        textMesh.rotation.set(0, 0, 0);
        // textMesh.position.copy(position);

        g.scene.add(textMesh);
    });
}

function createNavBar() {
    createTextMesh('Home', new THREE.Vector3(0, 0, 0));
}

createNavBar();
