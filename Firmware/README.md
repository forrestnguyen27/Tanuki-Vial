# Tanuki 40% keyboard
### [Firmware files](https://github.com/qmk/qmk_firmware/tree/master/keyboards/tanuki)

#### Why are these files here?
The firmware files are also hosted over at [QMK](https://github.com/qmk/qmk_firmware/tree/master/keyboards/tanuki) and should be used to compile the firmware in a way that you like. These files are posted here to consolidate the files in one place and allow people to compile using older versions of QMK.

#### What do I do with this?
The existing `tanuki_default_pcb_pro_micro.hex` is the original QMK firmware; it is not Vial firmware. For Vial, use the source and build steps below to compile a Vial-enabled HEX for your Tanuki PCB.

#### Some notes on this firmware
This firmware release is for the PCB version only.

40% keyboard designed by Seth-Senpai. This repo is meant for the pcb version of the Tanuki. If you made any modifications to the board please make sure that the firmware reflects these changes.

If you decide to handwire a Tanuki just make sure to change the files correctly. If you're lost you can check out the [QMK hand wiring guide](https://docs.qmk.fm/#/hand_wire). The matrix is displayed below.

![matrix](https://github.com/SethSenpai/Tanuki/blob/master/Img/matrix.png?raw=true)

The pcb version uses a Pro Micro (atmel 32u4 based) controller.

## Build Vial firmware

Vial firmware can change key assignments and layers in the Vial application. The supplied Vial keymap starts with the stock Tanuki layout. It uses the Tab + Escape key combination to unlock Vial's protected settings: hold both keys while opening Vial's **Security → Unlock** action. The existing custom layer behavior and RGB underglow code are retained; the Vial layout editor does not expose the underglow controls.

1. Install the QMK build environment using the [QMK setup guide](https://docs.qmk.fm/#/newbs_getting_started).
2. Clone Vial's QMK fork in its own folder and initialize its submodules:

   ```sh
   git clone https://github.com/vial-kb/vial-qmk.git
   cd vial-qmk
   make git-submodule
   ```

3. Copy this repository's `QMK_files` folder contents into `vial-qmk/keyboards/tanuki/`, preserving the `keymaps/default` and `keymaps/vial` folders. In a shell opened at this repository, on Windows PowerShell:

   ```powershell
   Copy-Item .\QMK_files\* <path-to-vial-qmk>\keyboards\tanuki\ -Recurse -Force
   ```

   If `keyboards/tanuki` already exists in your checkout, back it up before copying so you can restore its original files.

4. From the `vial-qmk` folder, build the Vial keymap:

   ```sh
   make tanuki:vial
   ```

   The firmware build produces a `.hex` file in the Vial-QMK output folder (typically `vial-qmk/.build/`). Use that Vial build for the next step. If the build reports errors, this legacy keyboard source may need updates for the QMK version in the checkout.

## Flash a Pro Micro

1. Save a copy of the currently working firmware and note your current keymap before flashing. Connect the Pro Micro by USB; use a data-capable cable.
2. Install [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases) on Windows. Select the Vial `.hex` file built above, and select the **atmega32u4 / Caterina** controller/bootloader option if prompted.
3. Put the Pro Micro into its bootloader. If the PCB has a reset button, tap it twice quickly. Otherwise briefly connect the Pro Micro's **RST** pin to **GND** twice in quick succession. The bootloader serial port is available only for a few seconds.
4. In QMK Toolbox, select the bootloader's newly appearing COM port if it is not selected automatically, then click **Flash** as soon as the board enters bootloader mode. The board may disconnect and reconnect when flashing completes.
5. Start Vial and connect the keyboard. If Vial prompts that the keyboard is locked, hold **Tab + Escape** and choose **Security → Unlock**.

If the bootloader window is missed, reset the board again and immediately click **Flash**. The Pro Micro bootloader is separate from the application firmware, so a failed application flash can usually be retried by entering the bootloader again. See the [QMK flashing guide](https://docs.qmk.fm/#/flashing) for other operating systems and flashing methods.

