#include <stdio.h>
#include <time.h>

enum moon_phases {
  WAXING_CRESCENT,
  FIRST_QUARTER,
  WAXING_GIBBOUS,
  FULL,
  WANING_GIBBOUS,
  THIRD_QUARTER,
  WANING_CRESCENT,
  NEW
};

static const char *phase_name(int phase) {
  static const char *const names[] = {
      "Waxing Crescent", "First Quarter", "Waxing Gibbous",  "Full",
      "Waning Gibbous",  "Third Quarter", "Waning Crescent", "New"};

  if (phase < 0 || phase >= (int)(sizeof(names) / sizeof(names[0]))) {
    return "Unknown";
  }
  return names[phase];
}

int moon_phase(int year, int month, int day) {
  int d, g, e;

  d = day;
  if (month == 2) {
    d += 31;
  } else if (month > 2) {
    d += 59 + (month - 3) * 30.6 + 0.5;
  }

  g = (year - 1990) % 19;
  e = (11 * g + 29) % 30;
  if (e == 25 || e == 24) {
    ++e;
  }
  return ((((e + d) * 6 + 5) % 177) / 22 & 7);
}

int main() {

  time_t now;
  struct tm *clock;
  int mp;

  time(&now);
  clock = localtime(&now);
  mp = moon_phase(clock->tm_year + 1900, clock->tm_mon + 1, clock->tm_mday);
  printf("The moon phase is %s (%i)\n", phase_name(mp), mp);
}