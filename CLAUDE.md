# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project overview

`MVC` is a Visual Studio C++ console application project (`MVC.slnx` / `MVC/MVC.vcxproj`), targeting C++20, built with the v145 platform toolset. The project currently contains no source files (`.cpp`/`.h`) yet — the `vcxproj` has empty `ItemGroup`s for source and header files.

This repo is **미션1: PoC 개발 — "MVC 스켈레톤 코드"** (per `docs/[CRA_AI] Day3_개인과제_반도체시료관리.pdf`, p.25): the deliverable is an MVC skeleton with Model/Controller/View package structure and clear role separation, as a PoC ahead of building the full 반도체 시료 생산주문관리 시스템 (semiconductor sample production/order management system). Data persistence, a monitoring tool, and a dummy-data generator are separate PoCs, not part of this repo.

When adding source files, place them under `MVC/` and register them (with the correct filter) in both `MVC/MVC.vcxproj` and `MVC/MVC.vcxproj.filters` — MSBuild only compiles files explicitly listed in the `.vcxproj`'s `ItemGroup`s, so new files must be added there or they will be silently ignored by the build.

## Domain and MVC design (from the spec PDF)

The target system manages 시료 inventory and 주문(Order) lifecycle through a production line. Design the skeleton's packages around these domain concepts:

**Model** — data + business rules, no I/O:
- `Sample`: 시료ID, 이름, 평균 생산시간, 수율, 재고 수량
- `Order`: 주문ID, 시료ID, 고객명, 주문 수량, 상태
- `ProductionLine` / 생산 큐: FIFO queue of orders waiting to be produced, plus the order currently in production
- Order 상태 (state machine): `RESERVED` → (승인, 재고 충분) → `CONFIRMED` → (출고) → `RELEASE`; `RESERVED` → (승인, 재고 부족) → `PRODUCING` → (생산 완료) → `CONFIRMED` → `RELEASE`; `RESERVED` → (거절) → `REJECTED` (거절된 주문은 정상 흐름 밖이며 모니터링 대상에서 제외)
- Production math belongs in the Model: 실 생산량 = `ceil(부족분 / 수율)`, 총 생산 시간 = `평균 생산시간 * 실 생산량`

**Controller** — one controller per menu feature, orchestrates Model + View, contains no rendering logic:
- `SampleController`: 시료 등록/조회/검색
- `OrderController`: 주문 접수(RESERVED 생성), 승인(재고 확인 후 CONFIRMED 또는 PRODUCING 분기), 거절(REJECTED)
- `MonitoringController`: 상태별 주문 수 집계, 시료별 재고 현황(여유/부족/고갈) 계산
- `ReleaseController`: CONFIRMED 주문의 출고 처리(→ RELEASE)
- `ProductionController`: 생산 큐 진행, 생산 완료 시 PRODUCING → CONFIRMED 전환
- `MainController`: 메인 메뉴에서 위 컨트롤러들로 라우팅

**View** — pure display/input prompts, no business logic:
- `MainMenuView`: 메뉴 선택 화면
- `SampleView`, `OrderView`, `MonitoringView`, `ReleaseView`, `ProductionLineView`: 각 기능별 화면 (화면 구성은 자유— PDF의 예시 UI는 참고용)

Keep Model classes free of console I/O and View classes free of business logic; Controllers are the only layer allowed to call both.

## Build

This is a Visual Studio C++ project, not a CMake/Makefile project. Build via Visual Studio or MSBuild directly:

```
msbuild MVC.slnx /p:Configuration=Debug /p:Platform=x64
msbuild MVC.slnx /p:Configuration=Release /p:Platform=x64
```

Supported platform/configuration combinations: `Debug|x64`, `Release|x64`, `Debug|Win32`, `Release|Win32`.

There is no test project, test framework, or lint configuration set up in this repository yet.
