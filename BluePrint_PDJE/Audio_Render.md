Defines the process of audio.

The process of audio rendering can be categorized into three main types: [[FullPreRender]], [[Hybrid Render]], and [[FullManualRender]].

- **[[FullPreRender]]** refers to pre-processed audio rendering done before playback.
- **[[Hybrid Render]]** processes audio in real-time during playback, adapting dynamically to changes.
- **[[FullManualRender]]** is a specialized rendering mode that relies entirely on external manipulation, requiring direct control or mechanical adjustment by actively listening to the audio.
	If you're planning to use this mode for DJing, you must have the skills to perform **beat matching** manually without relying on automated tools.

```mermaid
flowchart TD
MixBinary --> MixTranslator
MixTranslator --> MixMachine
MixMachine -->|Rendered Audio| ManualRender
ManualRender --> AudioPlay
```



See [[MixTranslator]], [[MixMachine]] 